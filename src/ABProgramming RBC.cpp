// ABProgramming RBC.cpp: define el punto de entrada de la aplicación.

#include <iostream>
#include "Paciente.hpp"
#include "Medico.hpp"
#include "Cita.hpp"
#include "HistorialClinico.hpp"
#include "Gestion.hpp"

using namespace std;

void mostrarMenu() {
    cout << "===============================" << endl;
    cout << "Sistema de Gestion Hospitalaria" << endl;
    cout << "===============================" << endl;
    cout << "1. Registrar Paciente" << endl;
    cout << "2. Registrar Medico" << endl;
    cout << "3. Agendar Cita" << endl;
    cout << "4. Consultar Historial Clinico" << endl;
    cout << "5. Generar Reporte" << endl;
    cout << "5. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

int main() {
    Gestion gestion;
    int opcion = 0;

    try {
        gestion.cargarDesdeArchivo();
    }
    catch (const exception& e) {
        cout << "Error al cargar los datos: " << e.what() << endl;
    }

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
        case 1: {
            gestion.registrarPaciente();
            break;
        }
        case 2: {
            gestion.registrarMedico();
            break;
        }
        case 3: {
            gestion.agendarCita();
            break;
        }
        case 4: {
            string tipoReporte;
            cout << "Tipos de reporte disponibles: pacientes, citas." << endl;
            cout << "Ingrese el tipo de reporte: ";
            cin >> tipoReporte;
            gestion.generarReporte(tipoReporte);
            break;
        }
        case 5: {
            string idPaciente;
            cout << "Ingrese el ID del paciente: ";
            cin >> idPaciente;
            bool encontrado = false;
            for (const auto& p : gestion.getPacientes()) {
                if (p->getID() == idPaciente) {
                    p->consultarHistorial();
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                cout << "Paciente no encontrado." << endl;
            }
            break;
        }
        case 6:
            gestion.guardarEnArchivo();
            cout << "Datos guardados. Saliendo del sistema..." << endl;
            break;
        default:
            cout << "Opción no válida. Intente de nuevo." << endl;
        }

    } while (opcion != 6);

    return 0;
}
