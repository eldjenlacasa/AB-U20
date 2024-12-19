#include <iostream>
#include "Sistema.h"

using namespace std;

int main() {
    Sistema sistema;
    int opcion;

    do {
        cout << "=== Sistema de Gesti�n Hospitalaria ===" << endl;
        cout << "1. Registrar paciente" << endl;
        cout << "2. Registrar m�dico" << endl;
        cout << "3. Programar cita" << endl;
        cout << "4. Mostrar todas las citas" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opci�n: ";
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
            string nombre, especialidad;
            cout << "Ingrese el ID del m�dico: ";
            cin >> id;
            cin.ignore();
            cout << "Ingrese el nombre del m�dico: ";
            getline(cin, nombre);
            cout << "Ingrese la especialidad del m�dico: ";
            getline(cin, especialidad);
            sistema.registrarMedico(id, nombre, especialidad);
            break;
        }
        case 3: {
            int citaId, pacienteId, medicoId;
            string fecha;
            bool urgencia;
            cout << "Ingrese el ID de la cita: ";
            cin >> citaId;
            cin.ignore();
            cout << "Ingrese la fecha de la cita (YYYY-MM-DD): ";
            getline(cin, fecha);
            cout << "�Es urgente? (1 para S�, 0 para No): ";
            cin >> urgencia;
            cout << "Ingrese el ID del paciente: ";
            cin >> pacienteId;
            cout << "Ingrese el ID del m�dico: ";
            cin >> medicoId;
            sistema.programarCita(citaId, fecha, urgencia, pacienteId, medicoId);
            break;
        }
        case 4:
            sistema.mostrarCitas();
            break;
        case 5:
            cout << "Saliendo del sistema..." << endl;
            break;
        default:
            cout << "Opci�n no v�lida. Intente nuevamente." << endl;
        }

        cout << endl;
    } while (opcion != 5);

    return 0;
}
