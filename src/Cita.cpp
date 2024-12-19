#include "Cita.hpp"
#include <iostream>

Cita::Cita(const std::string& fecha, const std::string& hora, int urgencia, Paciente* paciente, Medico* medico)
    : fecha(fecha), hora(hora), urgencia(urgencia), paciente(paciente), medico(medico) {}

void Cita::mostrarCita() const {
    std::cout << "Fecha: " << fecha << ", Hora: " << hora << std::endl;
    std::cout << "Paciente: " << paciente->getID() << std::endl;
    std::cout << "Medico: " << medico->getNombre() << " (" << medico->getEspecialidad() << ")" << std::endl;
    std::cout << "Urgencia: " << urgencia << std::endl;
}

void Cita::cancelarCita() {
    fecha = ""; 
    hora = "";
}

void Cita::modificarCita() {
    std::cout << "Ingrese la nueva fecha: ";
    std::cin >> fecha;
    std::cout << "Ingrese la nueva hora: ";
    std::cin >> hora;
}