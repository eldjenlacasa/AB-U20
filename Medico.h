#ifndef MEDICO_H
#define MEDICO_H

#include <string>
#include <iostream> // Para std::cout

class Medico {
private:
    static int contadorId;   // Contador estático para generar IDs únicos
    int id;                  // ID del médico
    std::string nombre;      // Nombre del médico
    std::string especialidad; // Especialidad del médico

public:
    Medico(std::string nombre, std::string especialidad);
    Medico(int id, std::string nombre, std::string especialidad);

    int getId() const; // Declaración del método como const
    std::string getNombre() const; // Declaración del método como const
    std::string getEspecialidad() const; // Declaración del método como const

    void modificarDatos(std::string campo, std::string valor);
};

#endif
