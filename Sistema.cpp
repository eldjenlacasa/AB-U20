#include "Sistema.h"
#include "Paciente.h"
#include "Medico.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>



void Sistema::registrarPaciente(std::string nombre) {
    Paciente nuevoPaciente(nombre);
    pacientes.push_back(nuevoPaciente);
}

void Sistema::darDeBajaPaciente(int id) {
    auto it = std::remove_if(pacientes.begin(), pacientes.end(), [id](const Paciente& p) {
        return p.getId() == id;
        });
    if (it != pacientes.end()) {
        pacientes.erase(it, pacientes.end());
        std::cout << "Paciente con ID " << id << " dado de baja." << std::endl;
    }
    else {
        std::cout << "Paciente con ID " << id << " no encontrado." << std::endl;
    }
}

void Sistema::registrarMedico(std::string nombre, std::string especialidad) {
    Medico nuevoMedico(nombre, especialidad);
    medicos.push_back(nuevoMedico);
}

void Sistema::darDeBajaMedico(int id) {
    auto it = std::remove_if(medicos.begin(), medicos.end(), [id](const Medico& m) {
        return m.getId() == id;
        });
    if (it != medicos.end()) {
        medicos.erase(it, medicos.end());
        std::cout << "Medico con ID " << id << " dado de baja." << std::endl;
    }
    else {
        std::cout << "Medico con ID " << id << " no encontrado." << std::endl;
    }
}

void Sistema::programarCita(int citaId, std::string fecha, bool urgencia, int pacienteId, int medicoId) {
    Paciente* paciente = nullptr;
    Medico* medico = nullptr;

    for (auto& p : pacientes) {
        if (p.getId() == pacienteId) {
            paciente = &p;
            break;
        }
    }

    for (auto& m : medicos) {
        if (m.getId() == medicoId) {
            medico = &m;
            break;
        }
    }

    if (paciente && medico) {
        citas.push_back(Cita(citaId, fecha, urgencia, paciente, medico));
    }
}

void Sistema::mostrarCitas() {
    for (const auto& cita : citas) {
        cita.mostrarCita();
    }
}

void Sistema::guardarDatos() const {
    std::ofstream archivoPacientes("pacientes.txt");
    for (const auto& paciente : pacientes) {
        archivoPacientes << paciente.getId() << "," << paciente.getNombre() << std::endl;
    }
    archivoPacientes.close();

    std::ofstream archivoMedicos("medicos.txt");
    for (const auto& medico : medicos) {
        archivoMedicos << medico.getId() << "," << medico.getNombre() << "," << medico.getEspecialidad() << std::endl;
    }
    archivoMedicos.close();

    std::ofstream archivoCitas("citas.txt");
    for (const auto& cita : citas) {
        archivoCitas << cita.getId() << "," << cita.getFecha() << "," << cita.isUrgencia() << "," << cita.getPaciente()->getId() << "," << cita.getMedico()->getId() << std::endl;
    }
    archivoCitas.close();
}

void Sistema::backupDatos() const {
    std::ofstream backupFile("backup_datos.txt");
    if (backupFile.is_open()) {
        backupFile << "Pacientes:\n";
        for (const auto& paciente : pacientes) {
            backupFile << paciente.getId() << ", " << paciente.getNombre() << "\n";
        }

        backupFile << "\nMedicos:\n";
        for (const auto& medico : medicos) {
            backupFile << medico.getId() << ", " << medico.getNombre() << ", " << medico.getEspecialidad() << "\n";
        }

        backupFile << "\nCitas:\n";
        for (const auto& cita : citas) {
            backupFile << cita.getId() << ", " << cita.getFecha() << ", " << cita.isUrgencia() << ", " << cita.getPaciente()->getId() << ", " << cita.getMedico()->getId() << "\n";
        }

        backupFile.close();
        std::cout << "Backup realizado con exito." << std::endl;
    }
    else {
        std::cerr << "Error al abrir el archivo de backup." << std::endl;
    }
}

void Sistema::cargarDatos() {
    std::ifstream archivoPacientes("pacientes.txt");
    std::ifstream archivoMedicos("medicos.txt");
    std::ifstream archivoCitas("citas.txt");

    if (!archivoPacientes.is_open()) {
        std::cerr << "Error al abrir el archivo de pacientes." << std::endl;
    }
    else {
        std::string linea;
        while (std::getline(archivoPacientes, linea)) {
            std::stringstream ss(linea);
            int id;
            std::string nombre;
            ss >> id;
            ss.ignore();
            std::getline(ss, nombre);
            pacientes.push_back(Paciente(id, nombre));
        }
        archivoPacientes.close();
    }

    if (!archivoMedicos.is_open()) {
        std::cerr << "Error al abrir el archivo de medicos." << std::endl;
    }
    else {
        std::string linea;
        while (std::getline(archivoMedicos, linea)) {
            std::stringstream ss(linea);
            int id;
            std::string nombre, especialidad;
            ss >> id;
            ss.ignore();
            std::getline(ss, nombre, ',');
            std::getline(ss, especialidad);
            medicos.push_back(Medico(id, nombre, especialidad));
        }
        archivoMedicos.close();
    }

    if (!archivoCitas.is_open()) {
        std::cerr << "Error al abrir el archivo de citas." << std::endl;
    }
    else {
        std::string linea;
        while (std::getline(archivoCitas, linea)) {
            std::stringstream ss(linea);
            int citaId, pacienteId, medicoId;
            std::string fecha;
            bool urgencia;
            ss >> citaId >> pacienteId >> medicoId >> urgencia;
            ss.ignore();
            std::getline(ss, fecha);
            programarCita(citaId, fecha, urgencia, pacienteId, medicoId);
        }
        archivoCitas.close();
    }
}
