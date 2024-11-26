#include "Medico.h"
#include <iostream>

Medico::Medico(const std::string& nombre) : nombre(nombre) {}

void Medico::mostrarNombre() const {
    std::cout << "Nombre del médico: " << nombre << std::endl;
}