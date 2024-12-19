#include <iostream>
#include "Paciente.h"
#include "Medico.h"
#include "Cita.h"

using namespace std;

int main() {
    // Crear un paciente
    Paciente paciente1(1, "Juan Perez");

    // Crear un médico
    Medico medico1(101, "Dra. Smith", "Cardiología");

    // Crear una cita
    Cita cita1(1001, "2024-12-20", true, &paciente1, &medico1);

    // Mostrar detalles de la cita
    cita1.mostrarCita();

    // Actualizar la fecha de la cita
    cita1.actualizarFecha("2024-12-22");

    // Cancelar la cita
    cita1.cancelarCita();

    return 0;
}
