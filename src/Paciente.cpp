#include "Paciente.hpp"
#include <iostream>

Paciente::Paciente(const std::string& nombre, const std::string& dni, const std::string& fechaIngreso)
    : nombre(nombre), id(dni), fechaIngreso(fechaIngreso) {}

const std::string& Paciente::getID() const {
    return id; 
}

void Paciente::registrarDiagnostico(const std::string& diagnostico) {
    historial.agregarDiagnostico(diagnostico); 
}

void Paciente::consultarHistorial() const {
    std::cout << "Historial del paciente: " << nombre << " (DNI: " << id << ")" << std::endl;
    historial.consultarHistorial(); 
}
