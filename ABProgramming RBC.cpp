// ABProgramming RBC.cpp: define el punto de entrada de la aplicación.

#include <iostream>   // Para entrada/salida estándar
#include <string>     // Para usar std::string
#include <vector>     // Para usar std::vector
#include <windows.h>  // Para funciones específicas de Windows

#include "HistorialClinico.h" // Incluir el encabezado de HistorialClinico
#include "Paciente.h"         // Incluir el encabezado de Paciente

int main() {
    // Configurar la consola para permitir caracteres especiales
    SetConsoleOutputCP(CP_UTF8);

    // Crear un objeto de la clase Paciente
    Paciente paciente("José");
    paciente.mostrarNombre(); // Mostrar el nombre del paciente

    // Crear un objeto de la clase HistorialClinico
    HistorialClinico historial;
    historial.agregarRegistro("Consulta del 10 de octubre");
    historial.agregarRegistro("Consulta del 15 de octubre");

    // Mostrar los registros del historial clínico
    historial.mostrarRegistros();

    return 0;
}