// HistorialClinico.h
#ifndef HISTORIALCLINICO_H
#define HISTORIALCLINICO_H

#include <vector>
#include <string>

class HistorialClinico {
private:
    std::vector<std::string> registros; // Vector para almacenar los registros clínicos

public:
    void agregarRegistro(const std::string& registro); // Declaración del método agregarRegistro
};

#endif
