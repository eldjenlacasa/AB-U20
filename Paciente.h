#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>
#include <iostream> // Para std::cout
#include "HistorialClinico.h" // Ajusta la ruta de inclusión según sea necesario

class Paciente {
private:
    static int contadorId;   // Contador estático para generar IDs únicos
    int id;                  // ID del paciente
    std::string nombre;      // Nombre del paciente
    std::string direccion;   // Dirección de residencia
    std::string telefono;    // Teléfono de contacto
    HistorialClinico historial;   // Historial clínico del paciente

public:
    Paciente(std::string nombre);
    Paciente(int id, std::string nombre);

    int getId() const;
    std::string getNombre() const; // Declaración del método como const


    void modificarDatos(std::string campo, std::string valor);
    void agregarHistorialClinico(const std::string& registro);
};

#endif
