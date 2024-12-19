#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>

class Paciente {
private:
    int id;                  // ID del paciente
    std::string nombre;      // Nombre del paciente

public:
    int getId(); // Declaración del método
    Paciente(int id, std::string nombre);
    std::string getNombre(); // Declaración del método getNombre

};

#endif
