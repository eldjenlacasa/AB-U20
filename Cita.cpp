#include "Cita.h"
#include <iostream>

using namespace std;

// Constructor
Cita::Cita(int id, std::string fecha, bool urgencia, Paciente* paciente, Medico* medico)
    : id(id), fecha(fecha), urgencia(urgencia), paciente(paciente), medico(medico) {}

// Métodos de acceso
int Cita::getId() const {
    return id;
}

std::string Cita::getFecha() const {
    return fecha;
}

bool Cita::isUrgencia() const {
    return urgencia;
}

Paciente* Cita::getPaciente() const {
    return paciente;
}

Medico* Cita::getMedico() const {
    return medico;
}

// Método para mostrar detalles de la cita
void Cita::mostrarCita() const {
    cout << "ID de la cita: " << id << endl;
    cout << "Fecha: " << fecha << endl;
    cout << "Urgente: " << (urgencia ? "Si" : "No") << endl;
    cout << "Paciente: " << paciente->getNombre() << endl;
    cout << "Medico: " << medico->getNombre() << endl;
}

// Método para actualizar la fecha
void Cita::actualizarFecha(std::string nuevaFecha) {
    fecha = nuevaFecha;
    cout << "La fecha de la cita ha sido actualizada a: " << nuevaFecha << endl;
}

// Método para cancelar la cita
void Cita::cancelarCita() {
    cout << "La cita con ID " << id << " ha sido cancelada." << endl;
}
 