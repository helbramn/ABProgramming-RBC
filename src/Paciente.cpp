
#include "Paciente.h"
#include <iostream>

Paciente::Paciente(const std::string& nombre) : nombre(nombre) {}

void Paciente::mostrarNombre() const {
    std::cout << "Nombre del paciente: " << nombre << std::endl;
}