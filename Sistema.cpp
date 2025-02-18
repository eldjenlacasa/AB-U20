#include "Sistema.h"
#include <fstream>
#include <iostream>

void Sistema::registrarPaciente(int id, std::string nombre) {
    pacientes.push_back(Paciente(id, nombre));
}

void Sistema::registrarMedico(int id, std::string nombre, std::string especialidad) {
    medicos.push_back(Medico(id, nombre, especialidad));
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
    } else {
        std::cerr << "Paciente o Medico no encontrado." << std::endl;
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
    } else {
        std::cerr << "Error al abrir el archivo de backup." << std::endl;
    }
}
