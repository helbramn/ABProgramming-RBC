﻿// ABProgramming RBC.cpp: define el punto de entrada de la aplicación.

#include <iostream>
#include <fstream>
#include "Paciente.hpp"
#include "Medico.hpp"
#include "Cita.hpp"
#include "HistorialClinico.hpp"
#include "Gestion.hpp"
#include "FileManager.hpp"

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
    cout << "6. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

void inicializarSistema() {
    FileManager::crearCarpeta();
    std::ofstream archivo;
    archivo.open(FileManager::obtenerRutaArchivo("Pacientes.csv"), std::ios::app);
    archivo.close();

    archivo.open(FileManager::obtenerRutaArchivo("Medicos.csv"), std::ios::app);
    archivo.close();

    archivo.open(FileManager::obtenerRutaArchivo("Citas.csv"), std::ios::app);
    archivo.close();
}

int main() {
    Gestion gestion;
    try {
        inicializarSistema(); 
        std::cout << "Iniciando carga de datos...\n";
        gestion.cargarPacientes(); 
        gestion.cargarMedicos();
        gestion.cargarCitas();
        std::cout << "Todos los datos han sido cargados.\n";
    }
    catch (const exception& e) {
        cout << "Error al cargar los datos: " << e.what() << endl;
    }

    int opcion = 0;

    do {
        mostrarMenu();
        while (!(cin >> opcion)) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Entrada invalida. Por favor, ingrese un numero: ";
        }

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
            std::string idPaciente;
            std::cout << "Ingrese el ID del paciente: ";
            std::cin >> idPaciente;
            gestion.consultarHistorial(idPaciente);
            break;
        }
        case 5: {
            string tipoReporte;
            cout << "Tipos de reporte disponibles: pacientes, citas." << endl;
            cout << "Ingrese el tipo de reporte: ";
            cin >> tipoReporte;

            gestion.generarReporte(tipoReporte); 
            break;
        }

        case 6:
            gestion.guardarPacientes();
            gestion.guardarMedicos();
            gestion.guardarCitas();
            cout << "Datos guardados. Saliendo del sistema..." << endl;
            break;
        default:
            cout << "Opción no valida. Intente de nuevo." << endl;
        }

    } while (opcion != 6);

    return 0;
}
