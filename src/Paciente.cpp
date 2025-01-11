#include "Paciente.hpp"
#include <iostream>
#include <regex> 
Paciente::Paciente(const std::string& nombre, const std::string& dni, const std::string& fechaIngreso)
    : nombre(nombre), dni(dni), fechaIngreso(fechaIngreso) {
    if (!validarDNI(dni)) {
        throw std::invalid_argument("Formato de DNI invalido.");
    }
    id = "PAC_" + dni;
}

const std::string& Paciente::getID() const {
    return id; 
}

const std::string& Paciente::getDNI() const {
    return dni;
}

const std::string& Paciente::getNombre() const {
    return nombre;
}

const std::string& Paciente::getFechaIngreso() const {
    return fechaIngreso;
}

void Paciente::modificarDatos() {
    std::cout << "Ingrese el nuevo nombre: ";
    std::cin.ignore();
    std::getline(std::cin, nombre);
    std::cout << "Ingrese la nueva fecha de ingreso: ";
    std::cin >> fechaIngreso;
}

bool Paciente::validarDNI(const std::string& dni) {
    std::regex dniRegex("^[0-9]{8}[A-Za-z]$"); 
    bool esValido = std::regex_match(dni, dniRegex);

    if (!esValido) {
        std::cout << "DNI inválido. Asegúrese de ingresar 8 dígitos seguidos de una letra." << std::endl;
    }
    return esValido;
}

bool Paciente::buscarPaciente(const std::string& criterio) {
    if (criterio == id || criterio == dni || criterio == nombre) {
        std::cout << "Paciente encontrado: " << nombre << " (ID: " << id << ", DNI: " << dni << ")" << std::endl;
        return true;
    }
    std::cout << "Paciente no encontrado." << std::endl;
    return false;
}

void Paciente::registrarDiagnostico(const std::string& diagnostico) {
    historial.agregarDiagnostico(diagnostico);
}

void Paciente::consultarHistorial() const {
    std::cout << "Historial del paciente: " << nombre << " (ID: " << id << ", DNI: " << dni << ")" << std::endl;
    historial.consultarHistorial();
}
