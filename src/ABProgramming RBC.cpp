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
    cout << "5. Generar Reporte de Pacientes por Fecha\n";
    cout << "6. Generar Reporte de Citas por Especialidad\n";
    cout << "7. Ordenar Citas por Fecha\n";
    cout << "8. Guardar Datos\n";
    cout << "9. Cargar Datos\n";
    cout << "5. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

int main() {
    Gestion gestion;
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore(); // Limpiar buffer

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
            gestion.consultarHistorial();
            break;
        }
        case 5: {
            string fechaInicio, fechaFin;
            cout << "Ingrese la fecha de inicio (YYYY-MM-DD): ";
            cin >> fechaInicio;
            cout << "Ingrese la fecha de fin (YYYY-MM-DD): ";
            cin >> fechaFin;
            gestion.reportePacientesPorFecha(fechaInicio, fechaFin);
            break;
        }
        case 6: {
            string especialidad;
            cout << "Ingrese la especialidad: ";
            cin >> especialidad;
            gestion.reporteCitasPorEspecialidad(especialidad);
            break;
        }
        case 7: {
            gestion.ordenarCitasPorFecha();
            break;
        }
        case 8: {
            gestion.guardarDatos();
            break;
        }
        case 9: {
            gestion.cargarDatos();
            break;
        }
        case 0: {
            cout << "Saliendo del sistema.\n";
            break;
        }
        default: {
            cout << "Opcion invalida. Intente de nuevo.\n";
            break;
        }
        }
    } while (opcion != 0);

    return 0;
}
