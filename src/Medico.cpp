#include "Medico.h"
#include <iostream>
#include "Paciente.h"

Medico::Medico(const std::string& nombre){ : nombre(nombre) {}

void Medico::mostrarNombre() const {
    std::cout << "Nombre del médico: " << Paciente::nombre << std::endl;
}