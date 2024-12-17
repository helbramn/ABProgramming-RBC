#include "Medico.hpp"

Medico::Medico(const std::string& nombre, const std::string& especialidad)
    : nombre(nombre), especialidad(especialidad), disponible(true) {}

const std::string& Medico::getEspecialidad() const {
    return especialidad;
}

bool Medico::isDisponible() const {
    return disponible;
}

void Medico::setDisponibilidad(bool estado) {
    disponible = estado;
}