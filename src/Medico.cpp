#include "Medico.hpp"
#include <iostream>

Medico::Medico(const std::string& nombre, const std::string& especialidad)
    : nombre(nombre), especialidad(especialidad), disponible(true) {}

const std::string& Medico::getNombre() const {
    return especialidad; 
}

const std::string& Medico::getEspecialidad() const {
    return especialidad;
}

bool Medico::isDisponible() const {
    return disponible;
}

void Medico::setDisponibilidad(bool estado) {
    disponible = estado;
}

void Medico::listarPorEspecialidad(const std::string& especialidad) {
    std::cout << "Mostrando médicos con especialidad: " << especialidad << std::endl;
}