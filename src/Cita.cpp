#include "Cita.hpp"
#include <iostream>
#include <algorithm>

Cita::Cita(const std::string& fecha, Paciente* paciente, Medico* medico)
    : fecha(fecha), paciente(paciente), medico(medico) {}

void Cita::mostrarCita() const {
    std::cout << "Fecha: " << fecha << std::endl;
    std::cout << "Paciente: " << paciente->getID() << std::endl;
    std::cout << "Medico: " << medico->getNombre() << " (" << medico->getEspecialidad() << ")" << std::endl;
}

bool Cita::cancelarCita() {
    if (fecha.empty()) {
        std::cout << "La cita ya esta cancelada." << std::endl;
        return false;
    }
    fecha.clear(); 
    std::cout << "Cita cancelada con exito." << std::endl;
    return true;
}

void Cita::modificarCita() {
    std::cout << "Ingrese la nueva fecha (DD-MM-YYYY): ";
    std::cin >> fecha;
    std::cout << "Cita modificada con exito." << std::endl;
}

void Cita::ordenarCitasPorFecha(std::vector<Cita*>& citas) {
    std::sort(citas.begin(), citas.end(), [](Cita* a, Cita* b) {
        return a->fecha < b->fecha; 
        });

    std::cout << "Citas ordenadas por fecha." << std::endl;
}

std::string Cita::getFecha() const {
    return fecha;
}

Paciente* Cita::getPaciente() const {
    return paciente;
}

Medico* Cita::getMedico() const {
    return medico;
}