#ifndef CITA_H
#define CITA_H

#include <string>
#include "Paciente.h"
#include "Medico.h"

class Cita {
private:
    int id;                     // ID de la cita
    std::string fecha;          // Fecha de la cita
    bool urgencia;              // �Es urgente?
    Paciente* paciente;         // Puntero al paciente
    Medico* medico;             // Puntero al m�dico

public:
    // Constructor
    Cita(int id, std::string fecha, bool urgencia, Paciente* paciente, Medico* medico);

    // M�todos
    void mostrarCita();
    void actualizarFecha(std::string nuevaFecha);
    void cancelarCita();
};

#endif
#pragma once
