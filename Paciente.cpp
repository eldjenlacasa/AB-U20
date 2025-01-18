// Paciente.cpp
#include "Paciente.h"
#include <string>
#include <stdexcept>

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

// Modificar datos del paciente
void Paciente::modificarDatos(std::string campo, std::string valor) {
    if (campo == "direccion") {
        direccion = valor;
    }
    else if (campo == "telefono") {
        // Validar que el teléfono tiene un formato básico
        if (valor.length() < 7 || valor.length() > 15) {
            throw std::invalid_argument("El teléfono debe tener entre 7 y 15 caracteres.");
        }
        telefono = valor;
    }
    else {
        throw std::invalid_argument("Campo no reconocido.");
    }
}

// Agregar un registro al historial clínico del paciente
void Paciente::agregarHistorialClinico(const std::string& registro) {
    historial.agregarRegistro(registro);
}