#include "Medico.h"

// Constructor
Medico::Medico(int id, std::string nombre, std::string especialidad) {
    this->id = id;
    this->nombre = nombre;
    this->especialidad = especialidad;
}

// Implementación de getNombre
std::string Medico::getNombre() {
    return nombre; // Devuelve el nombre del médico
}
