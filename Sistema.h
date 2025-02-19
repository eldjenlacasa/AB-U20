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
    void registrarPaciente(int id, std::string nombre);
    void darDeBajaPaciente(int id);
    void registrarMedico(int id, std::string nombre, std::string especialidad);
    void darDeBajaMedico(int id);
    void programarCita(int citaId, std::string fecha, bool urgencia, int pacienteId, int medicoId);
    void mostrarCitas();
    void guardarDatos() const;
    void backupDatos() const; // Nueva función para realizar el backup
    void cargarDatos(); // Nueva función para cargar los datos
};

#endif
