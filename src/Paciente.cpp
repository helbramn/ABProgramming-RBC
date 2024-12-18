#include "Paciente.hpp"
#include <iostream>

Paciente::Paciente(const std::string& nombre, const std::string& dni, const std::string& fechaIngreso)
    : nombre(nombre), dni(dni), fechaIngreso(fechaIngreso) {}

const std::string& Paciente::getDNI() const {
    return dni; 
}

void Paciente::registrarDiagnostico(const std::string& diagnostico) {
    historial.agregarDiagnostico(diagnostico); 
}

void Paciente::consultarHistorial() const {
    std::cout << "Historial del paciente: " << nombre << " (DNI: " << dni << ")" << std::endl;
    historial.consultarHistorial(); 
}
