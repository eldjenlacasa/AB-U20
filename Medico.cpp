#include "Medico.h"
#include <string>

// Constructor
Medico::Medico(int id, std::string nombre, std::string especialidad) {
    this->id = id;
    this->nombre = nombre;
    this->especialidad = especialidad;
}

// Implementación de getNombre
std::string Medico::getNombre() const { // Método const
    return nombre; // Devuelve el nombre del médico
}

int Medico::getId() const { // Método const
    return id;
}

// Implementación de getEspecialidad
std::string Medico::getEspecialidad() const { // Método const
    return especialidad; // Devuelve la especialidad del médico
}
