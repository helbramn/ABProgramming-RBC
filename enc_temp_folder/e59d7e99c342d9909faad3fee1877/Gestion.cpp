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
const std::vector<Paciente*>& Gestion::getPacientes() const {
    return pacientes;
}
void Gestion::registrarPaciente() {
    std::string nombre, dni, fechaIngreso;
    std::cout << "Ingrese el nombre del paciente: ";
    std::cin.ignore();
    std::getline(std::cin, nombre); 
    std::cout << "Ingrese el DNI del paciente: ";
    std::cin >> dni;
    std::cout << "Ingrese la fecha de ingreso (YYYY-MM-DD): ";
    std::cin >> fechaIngreso;

    pacientes.push_back(new Paciente(nombre, dni, fechaIngreso));
    std::cout << "Paciente registrado con éxito." << std::endl;
}
void Gestion::generarReporte(const std::string& tipo) {
    if (tipo == "pacientes") {
        std::cout << "Reporte de pacientes:" << std::endl;
        for (const auto& p : pacientes) {
            std::cout << "- " << p->getID() << ": " << p->getNombre() << std::endl;
        }
    }
    else if (tipo == "citas") {
        std::cout << "Reporte de citas:" << std::endl;
        for (const auto& c : citas) {
            c->mostrarCita();
        }
    }
    else {
        std::cout << "Tipo de reporte no reconocido." << std::endl;
    }
}

void Gestion::guardarEnArchivo() {
    std::ofstream archivo("datos.csv");
    if (!archivo.is_open()) {
        std::cout << "Error al abrir el archivo para guardar." << std::endl;
        return;
    }

    archivo << "Pacientes\n";
    for (const auto& p : pacientes) {
        archivo << p->getID() << "," << p->getNombre() << "," << p->getFechaIngreso() << "\n";
    }

    archivo << "Medicos\n";
    for (const auto& m : medicos) {
        archivo << m->getNombre() << "," << m->getEspecialidad() << "," << m->isDisponible() << "\n";
    }

    archivo.close();
    std::cout << "Datos guardados en datos.csv" << std::endl;
}

void Gestion::cargarDesdeArchivo() {
    std::ifstream archivo("datos.csv");
    if (!archivo.is_open()) {
        std::cout << "Error al abrir el archivo para cargar." << std::endl;
        return;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        std::cout << linea << std::endl; 
    }

    archivo.close();
    std::cout << "Datos cargados desde datos.csv" << std::endl;
}




void Gestion::registrarMedico() {
    std::cout << "Función registrarMedico no implementada aún." << std::endl;
}

void Gestion::agendarCita() {
    std::cout << "Función agendarCita no implementada aún." << std::endl;
}
