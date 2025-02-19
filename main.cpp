#include <iostream>
#include "Sistema.h"

using namespace std;

void menuGestionPacientes(Sistema& sistema) {
    int opcion;
    do {
        cout << "\n==== Gestión de Pacientes ====\n"
            << "1. Registrar paciente\n"
            << "2. Dar de baja paciente\n"
            << "0. Volver al menú principal\n"
            << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
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
        case 2: {
            int id;
            cout << "Ingrese el ID del paciente a dar de baja: ";
            cin >> id;
            sistema.darDeBajaPaciente(id);
            break;
        }
        case 0:
            return;
        default:
            cout << "Opción no válida. Intente nuevamente." << endl;
        }
    } while (opcion != 0);
}

void menuGestionMedicos(Sistema& sistema) {
    int opcion;
    do {
        cout << "\n==== Gestión de Médicos ====\n"
            << "1. Registrar médico\n"
            << "2. Dar de baja médico\n"
            << "0. Volver al menú principal\n"
            << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            int id;
            string nombre, especialidad;
            cout << "Ingrese el ID del médico: ";
            cin >> id;
            cin.ignore();
            cout << "Ingrese el nombre del médico: ";
            getline(cin, nombre);
            cout << "Ingrese la especialidad del médico: ";
            getline(cin, especialidad);
            sistema.registrarMedico(id, nombre, especialidad);
            break;
        }
        case 2: {
            int id;
            cout << "Ingrese el ID del médico a dar de baja: ";
            cin >> id;
            sistema.darDeBajaMedico(id);
            break;
        }
        case 0:
            return;
        default:
            cout << "Opción no válida. Intente nuevamente." << endl;
        }
    } while (opcion != 0);
}

void menuGestionCitas(Sistema& sistema) {
    int opcion;
    do {
        cout << "\n==== Gestión de Citas ====\n"
            << "1. Programar cita\n"
            << "2. Mostrar todas las citas\n"
            << "0. Volver al menú principal\n"
            << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            int citaId, pacienteId, medicoId;
            string fecha;
            bool urgencia;
            cout << "Ingrese el ID de la cita: ";
            cin >> citaId;
            cin.ignore();
            cout << "Ingrese la fecha de la cita (YYYY-MM-DD): ";
            getline(cin, fecha);
            cout << "Es urgente? (1 para Sí, 0 para No): ";
            cin >> urgencia;
            cout << "Ingrese el ID del paciente: ";
            cin >> pacienteId;
            cout << "Ingrese el ID del médico: ";
            cin >> medicoId;
            sistema.programarCita(citaId, fecha, urgencia, pacienteId, medicoId);
            break;
        }
        case 2:
            sistema.mostrarCitas();
            break;
        case 0:
            return;
        default:
            cout << "Opción no válida. Intente nuevamente." << endl;
        }
    } while (opcion != 0);
}

void menuManejoArchivos(Sistema& sistema) {
    int opcion;
    do {
        cout << "\n==== Manejo de Archivos ====\n"
            << "1. Guardar datos\n"
            << "2. Realizar backup\n"
            << "0. Volver al menú principal\n"
            << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            sistema.guardarDatos();
            cout << "Datos guardados." << endl;
            break;
        case 2:
            sistema.backupDatos();
            break;
        case 0:
            return;
        default:
            cout << "Opción no válida. Intente nuevamente." << endl;
        }
    } while (opcion != 0);
}

void menuPrincipal(Sistema& sistema) {
    int opcion;
    do {
        cout << "\n==== Menú Principal ====\n"
            << "1. Gestión de Pacientes\n"
            << "2. Gestión de Médicos\n"
            << "3. Gestión de Citas\n"
            << "4. Manejo de Archivos\n"
            << "0. Salir\n"
            << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            menuGestionPacientes(sistema);
            break;
        case 2:
            menuGestionMedicos(sistema);
            break;
        case 3:
            menuGestionCitas(sistema);
            break;
        case 4:
            menuManejoArchivos(sistema);
            break;
        case 0:
            cout << "Saliendo del sistema..." << endl;
            break;
        default:
            cout << "Opción no válida. Intente nuevamente." << endl;
        }
    } while (opcion != 0);
}

int main() {
    setlocale(LC_ALL, "");

    Sistema sistema;
    sistema.cargarDatos(); // Cargar datos al iniciar el sistema
    menuPrincipal(sistema);
    return 0;
}
