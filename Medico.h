#ifndef MEDICO_H
#define MEDICO_H

#include <string>

class Medico {
private:
    int id;                  // ID del médico
    std::string nombre;      // Nombre del médico
    std::string especialidad; // Especialidad del médico

public:
    int getId() const; // Declaración del método como const
    Medico(int id, std::string nombre, std::string especialidad);
    std::string getNombre() const; // Declaración del método como const
    std::string getEspecialidad() const; // Declaración del método como const
};

#endif
