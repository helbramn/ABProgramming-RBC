#include "Medico.hpp"
#include <iostream>

Medico::Medico(const std::string& nombre, const std::string& especialidad, bool disponible)
    : nombre(nombre), especialidad(especialidad), disponible(disponible) {}

const std::string& Medico::getNombre() const {
    return nombre; 
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

void Medico::listarPorEspecialidad(const std::vector<Medico*>& medicos, const std::string& especialidad) {
    std::cout << "Medicos con especialidad: " << especialidad << std::endl;
    for (const auto& medico : medicos) {
        if (medico->getEspecialidad() == especialidad) {
            std::cout << "- " << medico->getNombre()
                << " (Disponible: " << (medico->isDisponible() ? "Sí" : "No") << ")"
                << std::endl;
        }
    }
}