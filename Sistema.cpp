#include "Sistema.h"
#include <string>
#include <iostream>

using namespace std;

void Sistema::registrarPaciente(int id, string nombre) {
    pacientes.emplace_back(id, nombre);
    cout << "Paciente registrado: " << nombre << endl;
}

void Sistema::registrarMedico(int id, string nombre, string especialidad) {
    medicos.emplace_back(id, nombre, especialidad);
    cout << "Médico registrado: " << nombre << " (" << especialidad << ")" << endl;
}

void Sistema::programarCita(int citaId, string fecha, bool urgencia, int pacienteId, int medicoId) {
    Paciente* paciente = nullptr;
    Medico* medico = nullptr;

    // Buscar el paciente por ID
    for (auto& p : pacientes) {
        if (p.getId() == pacienteId) {
            paciente = &p;
            break;
        }
    }

    // Buscar el médico por ID
    for (auto& m : medicos) {
        if (m.getId() == medicoId) {
            medico = &m;
            break;
        }
    }

    if (paciente && medico) {
        citas.emplace_back(citaId, fecha, urgencia, paciente, medico);
        cout << "Cita programada: Paciente " << paciente->getNombre()
            << " con Médico " << medico->getNombre() << " el " << fecha << endl;
    }
    else {
        cout << "Error: Paciente o Médico no encontrado." << endl;
    }
}

void Sistema::mostrarCitas() {
    cout << "=== Lista de Citas ===" << endl;
    for (auto& cita : citas) {
        cita.mostrarCita();
    }
}
