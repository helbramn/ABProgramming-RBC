#include "Gestion.hpp"
#include <iostream>
#include <fstream>
#include <algorithm> 
#include <sstream>   
Gestion::Gestion() {}

Gestion::~Gestion() {
    for (auto p : pacientes) delete p;
    for (auto m : medicos) delete m;
    for (auto c : citas) delete c;
}
void Gestion::guardarDatos() {
    std::ofstream archivoPacientes("pacientes.txt");
    for (auto p : pacientes) {
        archivoPacientes << p->getID() << "," << p->getDNI() << "," << p->getNombre() << "\n";
    }
    archivoPacientes.close();

    std::ofstream archivoMedicos("medicos.txt");
    for (auto m : medicos) {
        archivoMedicos << m->getNombre() << "," << m->getEspecialidad() << "\n";
    }
}
void Gestion::cargarDatos() {
    std::ifstream archivoPacientes("pacientes.txt");
    std::string linea;
    while (getline(archivoPacientes, linea)) {
        std::istringstream stream(linea);
        std::string nombre, dni, fechaIngreso;
        getline(stream, nombre, ','); 
        getline(stream, fechaIngreso, ',');
        pacientes.push_back(new Paciente(nombre, dni, fechaIngreso));
    }
    archivoPacientes.close();

    std::ifstream archivoMedicos("medicos.txt");
    while (getline(archivoMedicos, linea)) {
        std::istringstream stream(linea);
        std::string nombre, especialidad;
        getline(stream, nombre, ',');
        getline(stream, especialidad, ',');
        medicos.push_back(new Medico(nombre, especialidad));
    }
    archivoMedicos.close();
}

void Gestion::reportePacientesPorFecha(const std::string& fechaInicio, const std::string& fechaFin) {
    std::cout << "Pacientes atendidos entre " << fechaInicio << " y " << fechaFin << ":\n";
    for (auto p : pacientes) {
        if (p->getFechaIngreso() >= fechaInicio && p->getFechaIngreso() <= fechaFin) {
            std::cout << p->getNombre() << "\n";
        }
    }
}

void Gestion::reporteCitasPorEspecialidad(const std::string& especialidad) {
    std::cout << "Citas pendientes para la especialidad: " << especialidad << "\n";
    for (auto c : citas) {
        if (c->getMedico()->getNombre() == especialidad) {
            c->mostrarCita();
        }
    }
}

// Ordenación
void Gestion::ordenarCitasPorFecha() {
    std::sort(citas.begin(), citas.end(), [](Cita* a, Cita* b) {
        return a->getFecha() < b->getFecha();
        });
    // Error: Olvidé verificar si el vector de citas está vacío.
    for (auto c : citas) {
        c->mostrarCita();
    }
}