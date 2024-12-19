#include "Cita.hpp"
#include <iostream>

Cita::Cita(const std::string& fecha, const std::string& hora, Paciente* paciente, Medico* medico)
    : fecha(fecha), hora(hora), paciente(paciente), medico(medico) {}

void Cita::mostrarCita() const {
    std::cout << "Cita programada:" << std::endl;
    std::cout << "Fecha: " << fecha << ", Hora: " << hora << std::endl;
    std::cout << "Paciente: " << paciente->getID() << std::endl;
    std::cout << "Medico: " << medico->getNombre() << " (" << medico->getEspecialidad() << ")" << std::endl;
}