#include <iostream>
#include "Sistema.h"

using namespace std;

int main() {
    Sistema sistema;
    sistema.cargarDatos(); // Cargar datos al iniciar el sistema
    int opcion;

    do {
        cout << "=== Sistema de Gestion Hospitalaria ===" << endl;
        cout << "1. Registrar paciente" << endl;
        cout << "2. Dar de baja paciente" << endl;
        cout << "3. Registrar medico" << endl;
        cout << "4. Dar de baja medico" << endl;
        cout << "5. Programar cita" << endl;
        cout << "6. Mostrar todas las citas" << endl;
        cout << "7. Guardar datos" << endl;
        cout << "8. Salir" << endl;
        cout << "9. Realizar backup" << endl;
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
            //Dar de baja Paciente
        case 2: {
            int id;
            cout << "Ingrese el ID del paciente a dar de baja: ";
            cin >> id;
            sistema.darDeBajaPaciente(id);
            break;
        }
            //Registrar Medico
        case 3: {
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
            //Dar de baja Medico
        case 4: {
            int id;
            cout << "Ingrese el ID del medico a dar de baja: ";
            cin >> id;
            sistema.darDeBajaMedico(id);
            break;
        }
            //Programar Cita
        case 5: {
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
        case 6:
            sistema.mostrarCitas();
            break;
        case 7:
            //Guardar datos
            sistema.guardarDatos();
            cout << "Datos guardados." << endl;
            break;
        case 8:
            //Salir
            cout << "Saliendo del sistema..." << endl;
            break;
        case 9:
            //Realizar backup
            sistema.backupDatos();
            break;
        default:
            cout << "Opcion no valida. Intente nuevamente." << endl;
        }

        cout << endl;
    } while (opcion != 8);

    return 0;
}
