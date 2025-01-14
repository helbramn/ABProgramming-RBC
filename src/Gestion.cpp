#include "Gestion.hpp"
#include <iostream>
#include <fstream>
#include <algorithm> 
#include <sstream> 
#include <vector>
#include <regex>

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
    Paciente* nuevoPaciente = nullptr;
    std::cout << "Ingrese el nombre del paciente: ";
    std::cin.ignore();
    std::getline(std::cin, nombre); 
    do {
    std::cout << "Ingrese el DNI del paciente: ";
    std::getline(std::cin, dni);
    try {
        if (!Paciente::validarDNI(dni)) {
            throw std::invalid_argument("Formato de DNI invalido.");
        }
    }
    catch (const std::invalid_argument& e) {
        std::cout << e.what() << " Intente nuevamente.\n";
        dni.clear();
    }
    } while (dni.empty());
    do {
    std::cout << "Ingrese la fecha de ingreso (YYYY-MM-DD): ";
    std::getline(std::cin, fechaIngreso);
    if (!validarFecha(fechaIngreso)) {
        std::cout << "Formato de fecha invalido. Intente nuevamente.\n";
        fechaIngreso.clear(); 
    }
    } while (fechaIngreso.empty());
    nuevoPaciente = new Paciente(nombre, dni, fechaIngreso);
    char opcion;
    std::cout << "¿Desea agregar historial clinico para este paciente? (S/N): ";
    std::cin >> opcion;
    if (toupper(opcion) == 'S') {
        std::cin.ignore();
        std::string diagnostico;
        std::cout << "Ingrese los diagnosticos separados por ';': ";
        std::getline(std::cin, diagnostico);
        nuevoPaciente->getHistorial().procesarDiagnosticos(diagnostico);

        std::string tratamiento;
        std::cout << "Ingrese los tratamientos separados por ';': ";
        std::getline(std::cin, tratamiento);
        nuevoPaciente->getHistorial().procesarTratamientos(tratamiento);

        std::string receta;
        std::cout << "Ingrese las recetas separadas por ';': ";
        std::getline(std::cin, receta);
        nuevoPaciente->getHistorial().procesarRecetas(receta);

        std::string cirugia;
        std::cout << "Ingrese las cirugias separadas por ';': ";
        std::getline(std::cin, cirugia);
        nuevoPaciente->getHistorial().procesarCirugias(cirugia);
    }
    pacientes.push_back(nuevoPaciente);

    std::cout << "\nPaciente registrado con éxito. Datos:\n";
    std::cout << "ID: " << nuevoPaciente->getID() << "\n";
    std::cout << "Nombre: " << nuevoPaciente->getNombre() << "\n";
    std::cout << "DNI: " << nuevoPaciente->getDNI() << "\n";
    std::cout << "Fecha de Ingreso: " << nuevoPaciente->getFechaIngreso() << "\n";
    std::cout << "Historial Clínico: \n";
    nuevoPaciente->consultarHistorial();
}

bool Gestion::validarFecha(const std::string& fecha) {
    std::regex fechaRegex("^\\d{4}-\\d{2}-\\d{2}$");
    return std::regex_match(fecha, fechaRegex);
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

void Gestion::registrarMedico() {
    std::string nombre, especialidad;
    bool disponible;

    std::cout << "Ingrese el nombre del medico: ";
    std::cin.ignore();
    std::getline(std::cin, nombre);

    std::cout << "Ingrese la especialidad del medico: ";
    std::getline(std::cin, especialidad);

    std::cout << "¿Esta disponible el medico? (1 para Si, 0 para No): ";
    std::cin >> disponible;

    Medico* nuevoMedico = new Medico(nombre, especialidad, disponible);
    medicos.push_back(nuevoMedico);
    std::cout << "Medico registrado con exito." << std::endl;
}

void Gestion::agendarCita() {
    std::string dniPaciente, nombreMedico, fecha;

    std::cout << "Ingrese el DNI del paciente: ";
    std::cin >> dniPaciente;
    std::cout << "Ingrese el nombre del medico: ";
    std::cin.ignore();
    std::getline(std::cin, nombreMedico);
    std::cout << "Ingrese la fecha de la cita (YYYY-MM-DD): ";
    std::cin >> fecha;


    auto itPaciente = std::find_if(pacientes.begin(), pacientes.end(), [&](Paciente* p) {
        return p->getID() == dniPaciente;
        });

    if (itPaciente == pacientes.end()) {
        std::cout << "Paciente no encontrado." << std::endl;
        return;
    }

    auto itMedico = std::find_if(medicos.begin(), medicos.end(), [&](Medico* m) {
        return m->getNombre() == nombreMedico;
        });

    if (itMedico == medicos.end()) {
        std::cout << "Medico no encontrado." << std::endl;
        return;
    }

    if (!(*itMedico)->isDisponible()) {
        std::cout << "El medico no está disponible para agendar citas." << std::endl;
        return;
    }


    Cita* nuevaCita = new Cita(fecha, *itPaciente, *itMedico);
    citas.push_back(nuevaCita);
    std::cout << "Cita agendada con exito." << std::endl;
}

void Gestion::consultarHistorial(const std::string& idPaciente) {
    auto it = std::find_if(pacientes.begin(), pacientes.end(), [&idPaciente](Paciente* p) {
        return p->getID() == idPaciente;
        });

    if (it != pacientes.end()) {
        (*it)->consultarHistorial(); 
    }
    else {
        std::cout << "Paciente no encontrado con ID: " << idPaciente << std::endl;
    }
}

void Gestion::guardarPacientes() {
    std::ofstream archivo("Pacientes.csv", std::ios::out);
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir Pacientes.csv para guardar." << std::endl;
        return;
    }

    archivo << "ID,DNI,Nombre,FechaIngreso,Diagnosticos,Tratamientos,Recetas,Cirugias\n";
    for (const auto& paciente : pacientes) {
        archivo << paciente->getID() << ","
            << paciente->getDNI() << ","
            << paciente->getNombre() << ","
            << paciente->getFechaIngreso() << ","
            << paciente->getHistorial().getDiagnosticosCSV() << ","
            << paciente->getHistorial().getTratamientosCSV() << ","
            << paciente->getHistorial().getRecetasCSV() << ","
            << paciente->getHistorial().getCirugiasCSV() << "\n";
    }

    archivo.close();
    std::cout << "Pacientes guardados exitosamente en Pacientes.csv." << std::endl;
}

void Gestion::cargarPacientes() {
    std::ifstream archivo("Pacientes.csv");
    if (!archivo.is_open()) {
        std::cerr << "Pacientes.csv no existe o no se puede abrir. Se creará al guardar nuevos pacientes." << std::endl;
        return;
    }

    std::string linea;
    getline(archivo, linea);
    while (std::getline(archivo, linea)) {
        std::istringstream stream(linea);
        std::string id, nombre, dni, fechaIngreso, diagnosticos, tratamientos, recetas, cirugias;;

        getline(stream, id, ',');
        getline(stream, nombre, ',');
        getline(stream, dni, ',');
        getline(stream, fechaIngreso, ',');
        getline(stream, diagnosticos, ',');
        getline(stream, tratamientos, ',');
        getline(stream, recetas, ',');
        getline(stream, cirugias, ',');

        Paciente* nuevoPaciente = new Paciente(nombre, dni, fechaIngreso);
        nuevoPaciente->getHistorial().procesarDiagnosticos(diagnosticos);
        nuevoPaciente->getHistorial().procesarTratamientos(tratamientos);
        nuevoPaciente->getHistorial().procesarRecetas(recetas);
        nuevoPaciente->getHistorial().procesarCirugias(cirugias);
        pacientes.push_back(nuevoPaciente);
    }

    archivo.close();
    std::cout << "Pacientes cargados exitosamente desde Pacientes.csv." << std::endl;
}

void Gestion::guardarMedicos() {
    std::ofstream archivo("Medicos.csv");
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir Medicos.csv para guardar." << std::endl;
        return;
    }

    for (const auto& medico : medicos) {
        archivo << medico->getNombre() << ","
            << medico->getEspecialidad() << ","
            << medico->isDisponible() << "\n";
    }

    archivo.close();
    std::cout << "Medicos guardados exitosamente en Medicos.csv." << std::endl;
}

void Gestion::cargarMedicos() {
    std::ifstream archivo("Medicos.csv");
    if (!archivo.is_open()) {
        std::cerr << "Medicos.csv no existe o no se puede abrir." << std::endl;
        return;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        std::istringstream stream(linea);
        std::string nombre, especialidad;
        bool disponible;

        std::getline(stream, nombre, ',');
        std::getline(stream, especialidad, ',');
        stream >> disponible;

        medicos.push_back(new Medico(nombre, especialidad, disponible));
    }

    archivo.close();
    std::cout << "Medicos cargados exitosamente desde Medicos.csv." << std::endl;
}

void Gestion::guardarCitas() {
    std::ofstream archivo("Citas.csv");
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir Citas.csv para guardar." << std::endl;
        return;
    }

    for (const auto& cita : citas) {
        archivo << cita->getFecha() << ","
            << cita->getPaciente()->getID() << ","
            << cita->getMedico()->getNombre() << "\n";
    }

    archivo.close();
    std::cout << "Citas guardadas exitosamente en Citas.csv." << std::endl;
}

void Gestion::cargarCitas() {
    std::ifstream archivo("Citas.csv");
    if (!archivo.is_open()) {
        std::cerr << "Citas.csv no existe o no se puede abrir." << std::endl;
        return;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        std::istringstream stream(linea);
        std::string fecha, hora, idPaciente, nombreMedico;

        std::getline(stream, fecha, ',');
        std::getline(stream, idPaciente, ',');
        std::getline(stream, nombreMedico, ',');

        Paciente* paciente = nullptr;
        Medico* medico = nullptr;

        for (const auto& p : pacientes) {
            if (p->getID() == idPaciente) {
                paciente = p;
                break;
            }
        }

        for (const auto& m : medicos) {
            if (m->getNombre() == nombreMedico) {
                medico = m;
                break;
            }
        }

        if (paciente && medico) {
            citas.push_back(new Cita(fecha, paciente, medico));
        }
    }

    archivo.close();
    std::cout << "Citas cargadas exitosamente desde Citas.csv." << std::endl;
}


