#ifndef MEDICO_H
#define MEDICO_H

#include <string>

class Medico {
private:
    int id;                  // ID del médico
    std::string nombre;      // Nombre del médico
    std::string especialidad; // Especialidad del médico

public:
    int getId(); // Declaración del método
    Medico(int id, std::string nombre, std::string especialidad);
    std::string getNombre(); // Declaración del método getNombre
};

#endif
