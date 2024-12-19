// ABProgramming RBC.cpp: define el punto de entrada de la aplicación.

#include <iostream>
#include "Paciente.hpp"
#include "Medico.hpp"
#include "Cita.hpp"
#include "HistorialClinico.hpp"
#include "Gestion.hpp"

using namespace std;

void mostrarMenu() {
    cout << "==============================" << endl;
    cout << "   Sistema de Gestión Hospitalaria" << endl;
    cout << "==============================" << endl;
    cout << "1. Registrar Paciente" << endl;
    cout << "2. Registrar Medico" << endl;
    cout << "3. Agendar Cita" << endl;
    cout << "4. Consultar Historial Clinico" << endl;
    cout << "5. Salir" << endl;
    cout << "Seleccione una opción: ";
}

int main() {
    int opcion = 0;
    Gestion gestion; 

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
        case 1:
            gestion.registrarPaciente();
            break;
        case 2:
            gestion.registrarMedico();
            break;
        case 3:
            gestion.agendarCita();
            break;
        case 4:
            gestion.consultarHistorial();
            break;
        case 5:
            cout << "Saliendo del sistema..." << endl;
            break;
        default:
            cout << "Opción no valida. Intente de nuevo." << endl;
        }

    } while (opcion != 5);

    return 0;
}
