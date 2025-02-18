#include "Medico.h"
#include <string>

// Constructor
Medico::Medico(int id, std::string nombre, std::string especialidad) {
    this->id = id;
    this->nombre = nombre;
    this->especialidad = especialidad;
}

// Implementaci�n de getNombre
std::string Medico::getNombre() const { // M�todo const
    return nombre; // Devuelve el nombre del m�dico
}

int Medico::getId() const { // M�todo const
    return id;
}

// Implementaci�n de getEspecialidad
std::string Medico::getEspecialidad() const { // M�todo const
    return especialidad; // Devuelve la especialidad del m�dico
}
