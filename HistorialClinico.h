// HistorialClinico.h
#ifndef HISTORIALCLINICO_H
#define HISTORIALCLINICO_H

#include <vector>
#include <string>

class HistorialClinico {
private:
    std::vector<std::string> registros;

public:
    void agregarRegistro(const std::string& registro);
};

#endif
