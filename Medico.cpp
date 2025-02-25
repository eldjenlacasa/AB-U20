#include "Medico.h"
#include <string>
#include <stdexcept>
#include <iostream>

int Medico::contadorId = 1;

Medico::Medico(std::string nombre, std::string especialidad) 
    : id(contadorId++), nombre(nombre), especialidad(especialidad) {
    std::cout << "Nuevo ID de m�dico asignado: " << id << std::endl; // Notificar al usuario
}
// Constructor con ID espec�fico
Medico::Medico(int id, std::string nombre, std::string especialidad)
    : id(id), nombre(nombre), especialidad(especialidad) {
    std::cout << "ID de m�dico asignado: " << id << std::endl; // Notificar al usuario
}
int Medico::getId() const { // Declaraci�n del m�todo como const
    return id;
}

std::string Medico::getNombre() const { // Declaraci�n del m�todo como const
    return nombre;
}

std::string Medico::getEspecialidad() const { // Declaraci�n del m�todo como const
    return especialidad;
}

void Medico::modificarDatos(std::string campo, std::string valor) {
    if (campo == "nombre") {
        nombre = valor;
    }
    else if (campo == "especialidad") {
        especialidad = valor;
    }
    else {
        throw std::invalid_argument("Campo no reconocido.");
    }
}