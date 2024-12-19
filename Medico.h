#ifndef MEDICO_H
#define MEDICO_H

#include <string>

class Medico {
private:
    int id;                  // ID del m�dico
    std::string nombre;      // Nombre del m�dico
    std::string especialidad; // Especialidad del m�dico

public:
    int getId(); // Declaraci�n del m�todo
    Medico(int id, std::string nombre, std::string especialidad);
    std::string getNombre(); // Declaraci�n del m�todo getNombre
};

#endif
