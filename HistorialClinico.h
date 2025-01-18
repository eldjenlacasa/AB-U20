// HistorialClinico.h
#ifndef HISTORIALCLINICO_H
#define HISTORIALCLINICO_H

#include <vector>
#include <string>

class HistorialClinico {
private:
    std::vector<std::string> registros; // Vector para almacenar los registros cl�nicos

public:
    void agregarRegistro(const std::string& registro); // Declaraci�n del m�todo agregarRegistro
};

#endif
