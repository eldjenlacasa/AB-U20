#ifndef SISTEMA_H
#define SISTEMA_H

#include <vector>
#include "Paciente.h"
#include "Medico.h"
#include "Cita.h"

class Sistema {
private:
    std::vector<Paciente> pacientes;
    std::vector<Medico> medicos;
    std::vector<Cita> citas;

public:
    void registrarPaciente(std::string nombre);
    void darDeBajaPaciente(int id);
    void registrarMedico(std::string nombre, std::string especialidad);
    void darDeBajaMedico(int id);
    void programarCita(int citaId, std::string fecha, bool urgencia, int pacienteId, int medicoId);
    void mostrarCitas();
    void guardarDatos() const;
    void backupDatos() const;
    void cargarDatos();
};

#endif
