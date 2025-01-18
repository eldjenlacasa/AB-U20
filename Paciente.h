#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>
#include "HistorialClinico.h" // Ajusta la ruta de inclusión según sea necesario

class Paciente {
private:
    int id;                  // ID del paciente
    std::string nombre;      // Nombre del paciente
    std::string direccion;        // Dirección de residencia
    std::string telefono;         // Teléfono de contacto
    HistorialClinico historial;   // Historial clínico del paciente

public:
    int getId(); // Declaración del método

    Paciente(int id, std::string nombre);

    std::string getNombre(); // Declaración del método getNombre

    void modificarDatos(std::string campo, std::string valor);
    void agregarHistorialClinico(const std::string& registro); // Cambiado el tipo de parámetro
};

#endif
