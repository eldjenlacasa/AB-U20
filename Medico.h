#ifndef MEDICO_H
#define MEDICO_H

#include <string>
#include <iostream> // Para std::cout

class Medico {
private:
    static int contadorId;   // Contador est�tico para generar IDs �nicos
    int id;                  // ID del m�dico
    std::string nombre;      // Nombre del m�dico
    std::string especialidad; // Especialidad del m�dico

public:
    Medico(std::string nombre, std::string especialidad);
    Medico(int id, std::string nombre, std::string especialidad);

    int getId() const; // Declaraci�n del m�todo como const
    std::string getNombre() const; // Declaraci�n del m�todo como const
    std::string getEspecialidad() const; // Declaraci�n del m�todo como const

    void modificarDatos(std::string campo, std::string valor);
};

#endif
