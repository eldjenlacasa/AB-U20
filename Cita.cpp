#include "Cita.h"
#include <iostream>
#include <string>

using namespace std;

// Constructor
Cita::Cita(int id, std::string fecha, bool urgencia, Paciente* paciente, Medico* medico) {
    this->id = id;
    this->fecha = fecha;
    this->urgencia = urgencia;
    this->paciente = paciente;
    this->medico = medico;
}

// Método para mostrar detalles de la cita
void Cita::mostrarCita() {
    cout << "ID de la cita: " << id << endl;
    cout << "Fecha: " << fecha << endl;
    cout << "Urgente: " << (urgencia ? "Sí" : "No") << endl;
    cout << "Paciente: " << paciente->getNombre() << endl;
    cout << "Médico: " << medico->getNombre() << endl;
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
