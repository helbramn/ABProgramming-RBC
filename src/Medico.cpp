#include "Medico.hpp"
#include <iostream>

using namespace std;

Medico::Medico(const string& nombre, const string& especialidad)
    : nombre(nombre), especialidad(especialidad), disponible(true) {}

const string& Medico::getEspecialidad() const {
    return especialidad;
}

const string& Medico::getNombre() const {
    return especialidad;
}

bool Medico::isDisponible() const {
    return disponible;
}

void Medico::setDisponibilidad(bool estado) {
    disponible = estado;
}