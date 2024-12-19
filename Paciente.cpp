#include "Paciente.h"
#include <string>

// Constructor
Paciente::Paciente(int id, std::string nombre) {
    this->id = id;
    this->nombre = nombre;
}

// Implementación de getNombre
std::string Paciente::getNombre() {
    return nombre; // Devuelve el nombre del paciente
}
int Paciente::getId() {
    return id;
}
