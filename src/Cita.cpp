#include "Cita.hpp"
#include <iostream>
#include <algorithm>

Cita::Cita(const std::string& fecha, const std::string& hora, int urgencia, Paciente* paciente, Medico* medico)
    : fecha(fecha), hora(hora), urgencia(urgencia), paciente(paciente), medico(medico) {}

void Cita::mostrarCita() const {
    std::cout << "Fecha: " << fecha << ", Hora: " << hora << std::endl;
    std::cout << "Paciente: " << paciente->getID() << std::endl;
    std::cout << "Medico: " << medico->getNombre() << " (" << medico->getEspecialidad() << ")" << std::endl;
    std::cout << "Urgencia: " << urgencia << std::endl;
}

void Cita::cancelarCita() {
    if (fecha.empty() && hora.empty()) {
        std::cout << "La cita ya está cancelada." << std::endl;
        return false;
    }
    fecha.clear(); 
    hora.clear();
    std::cout << "Cita cancelada con éxito." << std::endl;
    return true;
}

void Cita::modificarCita() {
    std::cout << "Ingrese la nueva fecha (DD-MM-YYYY): ";
    std::cin >> fecha;
    std::cout << "Ingrese la nueva hora (HH:MM): ";
    std::cin >> hora;
    std::cout << "Cita modificada con éxito." << std::endl;
}

void Cita::ordenarCitasPorFecha(std::vector<Cita*>& citas) {
    std::sort(citas.begin(), citas.end(), [](Cita* a, Cita* b) {
        return a->fecha < b->fecha; // Compara las fechas
        });

    std::cout << "Citas ordenadas por fecha." << std::endl;
}