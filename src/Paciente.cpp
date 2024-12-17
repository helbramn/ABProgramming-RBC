
#include "Paciente.hpp"
#include <iostream>

using namespace std;

Paciente::Paciente(const string& nombre, string& dni, string& fechaIngreso) {
    : nombre(nombre), dni(dni), fechaIngreso(fechaIngreso) {}

const string& Paciente::getDNI() const {
    return dni;
}

void Paciente::registrarDiagnostico(const string& diagnostico) {
    historial.agregarDiagnostico(diagnostico);
}

void Paciente::consultarHistorial() const {
    cout << "Historial del paciente: " << nombre << " (DNI: " << dni << ")" << endl;
    historial.consultarHistorial();
};
