#include "Gestion.hpp"
#include <iostream>

Gestion::Gestion() {}

Gestion::~Gestion() {
    for (auto p : pacientes) delete p;
    for (auto m : medicos) delete m;
    for (auto c : citas) delete c;
}

void Gestion::registrarPaciente() {
    std::string nombre, dni, fechaIngreso;
    std::cout << "Ingrese el nombre del paciente: ";
    std::cin >> nombre;
    std::cout << "Ingrese el DNI del paciente: ";
    std::cin >> dni;
    std::cout << "Ingrese la fecha de ingreso: ";
    std::cin >> fechaIngreso;

    pacientes.push_back(new Paciente(nombre, dni, fechaIngreso));
    std::cout << "Paciente registrado con éxito." << std::endl;
}

void Gestion::registrarMedico() {
    std::string nombre, especialidad;
    std::cout << "Ingrese el nombre del medico: ";
    std::cin >> nombre;
    std::cout << "Ingrese la especialidad del medico: ";
    std::cin >> especialidad;

    medicos.push_back(new Medico(nombre, especialidad));
    std::cout << "Medico registrado con éxito." << std::endl;
}

void Gestion::agendarCita() {
    std::string fecha, hora, dniPaciente, nombreMedico;
    std::cout << "Ingrese la fecha de la cita (YYYY-MM-DD): ";
    std::cin >> fecha;
    std::cout << "Ingrese la hora de la cita (HH:MM): ";
    std::cin >> hora;
    std::cout << "Ingrese el DNI del paciente: ";
    std::cin >> dniPaciente;
    std::cout << "Ingrese el nombre del medico: ";
    std::cin >> nombreMedico;

    Paciente* paciente = nullptr;
    Medico* medico = nullptr;

    for (auto p : pacientes) {
        if (p->getID() == dniPaciente) {
            paciente = p;
            break;
        }
    }

    for (auto m : medicos) {
        if (m->getNombre() == nombreMedico && m->isDisponible()) {
            medico = m;
            medico->setDisponibilidad(false);
            break;
        }
    }

    if (paciente && medico) {
        citas.push_back(new Cita(fecha, hora, paciente, medico));
        std::cout << "Cita agendada con exito." << std::endl;
    }
    else {
        std::cout << "Error al agendar la cita: paciente o medico no encontrado/disponible." << std::endl;
    }
}

void Gestion::consultarHistorial() {
    std::string dni;
    std::cout << "Ingrese el DNI del paciente: ";
    std::cin >> dni;

    for (auto p : pacientes) {
        if (p->getID() == dni) {
            p->consultarHistorial();
            return;
        }
    }

    std::cout << "Paciente no encontrado." << std::endl;
}
