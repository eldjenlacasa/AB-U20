#include <iostream>
#include "Sistema.h"

using namespace std;

int main() {
    Sistema sistema;
    int opcion;

    do {
        cout << "=== Sistema de Gestion Hospitalaria ===" << endl;
        cout << "1. Registrar paciente" << endl;
        cout << "2. Registrar medico" << endl;
        cout << "3. Programar cita" << endl;
        cout << "4. Mostrar todas las citas" << endl;
        cout << "5. Guardar datos y salir" << endl;
        cout << "6. Salir sin guardar" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            //Registrar Paciente
        case 1: {
            int id;
            string nombre;
            cout << "Ingrese el ID del paciente: ";
            cin >> id;
            cin.ignore();
            cout << "Ingrese el nombre del paciente: ";
            getline(cin, nombre);
            sistema.registrarPaciente(id, nombre);
            break;
        }
              //Registrar Medico
        case 2: {
            int id;
            string nombre, especialidad;
            cout << "Ingrese el ID del medico: ";
            cin >> id;
            cin.ignore();
            cout << "Ingrese el nombre del medico: ";
            getline(cin, nombre);
            cout << "Ingrese la especialidad del medico: ";
            getline(cin, especialidad);
            sistema.registrarMedico(id, nombre, especialidad);
            break;
        }
              //Programar Cita
        case 3: {
            int citaId, pacienteId, medicoId;
            string fecha;
            bool urgencia;
            cout << "Ingrese el ID de la cita: ";
            cin >> citaId;
            cin.ignore();
            cout << "Ingrese la fecha de la cita (YYYY-MM-DD): ";
            getline(cin, fecha);
            cout << "Es urgente? (1 para Si, 0 para No): ";
            cin >> urgencia;
            cout << "Ingrese el ID del paciente: ";
            cin >> pacienteId;
            cout << "Ingrese el ID del medico: ";
            cin >> medicoId;
            sistema.programarCita(citaId, fecha, urgencia, pacienteId, medicoId);
            break;
        }
            //Mostrar Citas
        case 4:
            sistema.mostrarCitas();
            break;
        case 5:
            //Guardar datos y salir
            sistema.guardarDatos();
            cout << "Datos guardados. Saliendo del sistema..." << endl;
            opcion = 6; // Para salir del bucle
            break;
        case 6:
            //Salir sin guardar
            cout << "Saliendo del sistema sin guardar..." << endl;
            break;
        default:
            cout << "Opcion no valida. Intente nuevamente." << endl;
        }

        cout << endl;
    } while (opcion != 6);

    return 0;
}
