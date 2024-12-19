#include "Paciente.hpp"
#include <iostream>
#include <regex> 
Paciente::Paciente(const std::string& nombre, const std::string& dni, const std::string& fechaIngreso)
    : nombre(nombre), dni(dni), fechaIngreso(fechaIngreso) {
    if (!validarDNI(dni)) {
        std::cout << "Error: Formato de DNI inv�lido." << std::endl; 
    }
    id = dni + "_ID"; 
}

const std::string& Paciente::getID() const {
    return dni; 
}

const std::string& Paciente::getDNI() const {
    return dni;
}

void Paciente::modificarDatos() {
    std::cout << "Ingrese el nuevo nombre: ";
    std::cin >> nombre; 
    std::cout << "Ingrese la nueva fecha de ingreso: ";
    std::cin >> fechaIngreso;
}

bool Paciente::validarDNI(const std::string& dni) {
    std::regex formatoDNI("[0-9]{8}[A-Z]"); 
    return std::regex_match(dni, formatoDNI);
}

bool Paciente::buscarPaciente(const std::string& criterio) {
    if (criterio == id || criterio == dni || criterio == nombre) {
        std::cout << "Paciente encontrado: " << nombre << " (ID: " << id << ", DNI: " << dni << ")" << std::endl;
        return true;
    }
    return false;
}

void Paciente::registrarDiagnostico(const std::string& diagnostico) {
    historial.agregarDiagnostico(diagnostico);
}

void Paciente::consultarHistorial() const {
    std::cout << "Historial del paciente: " << nombre << " (ID: " << id << ", DNI: " << dni << ")" << std::endl;
    historial.consultarHistorial();
}
