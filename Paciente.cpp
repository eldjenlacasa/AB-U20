#include "Paciente.h"
#include <string>
#include <stdexcept>
#include <iostream>

int Paciente::contadorId = 1; // Inicialización del contador estático

// Constructor que asigna automáticamente el ID
Paciente::Paciente(std::string nombre) : id(contadorId++), nombre(nombre) {
    std::cout << "Nuevo ID de paciente asignado: " << id << std::endl; // Notificar al usuario
}
// Constructor con ID específico
Paciente::Paciente(int id, std::string nombre) : id(id), nombre(nombre) {
    std::cout << "ID de paciente asignado: " << id << std::endl; // Notificar al usuario
}

// Implementación de getNombre
std::string Paciente::getNombre() const { // Declaración del método como const
    return nombre; // Devuelve el nombre del paciente
}

int Paciente::getId() const { // Declaración del método como const
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