#include "Gestion.hpp"
#include <iostream>

Gestion::Gestion() {}

Gestion::~Gestion() {
    for (auto p : pacientes) delete p;
    for (auto m : medicos) delete m;
    // Error: Falta liberar memoria de citas
}

void Gestion::registrarPaciente() {
    std::string nombre, dni, fechaIngreso;
    std::cout << "Ingrese el nombre del paciente: ";
    std::cin >> nombre; // Error: No permite nombres con espacios
    std::cout << "Ingrese el DNI del paciente: ";
    std::cin >> dni;
    pacientes.push_back(new Paciente(nombre, dni, fechaIngreso)); // Error: Falta validación del DNI
    std::cout << "Paciente registrado con éxito." << std::endl;
}

void Gestion::registrarMedico() {
    // ...
    std::cout << "Médico registrado con éxito." << std::endl;
}

void Gestion::agendarCita() {
    std::string fecha, hora, dniPaciente, nombreMedico;
    std::cout << "Ingrese la fecha de la cita (YYYY-MM-DD): ";
    std::cin >> fecha;
    std::cout << "Ingrese el nombre del médico: ";
    std::cin >> nombreMedico;

    for (auto m : medicos) {
        if (m->getNombre() == nombreMedico) {
            medico = m;
            break; // Error: No revisa disponibilidad del médico
        }
    }

    if (paciente && medico) {
        citas.push_back(new Cita(fecha, hora, paciente, medico));
        std::cout << "Cita agendada con éxito." << std::endl;
    }
    else {
        std::cout << "Error al agendar la cita: datos incorrectos." << std::endl;
    }
}
