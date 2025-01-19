#include "Gestion.hpp"
#include <iostream>
#include <fstream>
#include <algorithm> 
#include <sstream> 
#include <vector>
#include <regex>
#include "FileManager.hpp"

Gestion::Gestion() {}
Gestion::~Gestion() {
    for (auto p : pacientes) delete p;
    for (auto m : medicos) delete m;
    for (auto c : citas) delete c;

    pacientes.clear();
    medicos.clear();
    citas.clear();
}

const std::vector<Paciente*>& Gestion::getPacientes() const {
    return pacientes;
}

void Gestion::registrarPaciente() {
    std::string Pnombre, dni, fechaIngreso;
    Paciente* nuevoPaciente = nullptr;
    std::cout << "Ingrese el nombre del paciente: ";
    std::cin.ignore();
    std::getline(std::cin, Pnombre); 
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
    nuevoPaciente = new Paciente(Pnombre, dni, fechaIngreso);
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

    auto it = std::find_if(pacientes.begin(), pacientes.end(), [&](Paciente* p) {
        return p->getDNI() == dni;
        });
    if (it != pacientes.end()) {
        std::cout << "El paciente con DNI " << dni << " ya está registrado.\n";
        return;
    }
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
    std::string Mnombre, especialidad;
    bool disponible;

    std::cout << "Ingrese el nombre del medico: ";
    std::cin.ignore();
    std::getline(std::cin, Mnombre);

    std::cout << "Ingrese la especialidad del medico: ";
    std::getline(std::cin, especialidad);

    std::cout << "¿Esta disponible el medico? (1 para Si, 0 para No): ";
    std::cin >> disponible;

    Medico* nuevoMedico = new Medico(Mnombre, especialidad, disponible);
    medicos.push_back(nuevoMedico);
    std::cout << "Medico registrado con exito." << std::endl;

    auto it = std::find_if(medicos.begin(), medicos.end(), [&](Medico* p) {
        return p->getNombre() == Mnombre;
        });
    if (it != medicos.end()) {
        std::cout << "El medico con nombre " << Mnombre << " ya está registrado.\n";
        return;
    }
}

void Gestion::agendarCita() {
    std::string getID, nombreMedico, fecha;

    std::cout << "Ingrese el ID del paciente: ";
    std::cin >> getID;
    std::cout << "Ingrese el nombre del medico: ";
    std::cin.ignore();
    std::getline(std::cin, nombreMedico);
    std::cout << "Ingrese la fecha de la cita (YYYY-MM-DD): ";
    std::cin >> fecha;


    auto itPaciente = std::find_if(pacientes.begin(), pacientes.end(), [&](Paciente* p) {
        return p->getID() == getID;
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
    std::string archivoPacientes = FileManager::obtenerRutaArchivo("Pacientes.csv");
    std::cout << "Guardando pacientes en: " << archivoPacientes << std::endl;

    std::ofstream archivo(archivoPacientes, std::ios::app);
    archivo << "ID,DNI,Nombre,FechaIngreso,Diagnosticos,Tratamientos,Recetas,Cirugias\n";
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir " << archivoPacientes << " para guardar." << std::endl;
        return;
    }

    archivo << "ID,DNI,Nombre,FechaIngreso,Diagnosticos,Tratamientos,Recetas,Cirugias\n";
    for (const auto& paciente : pacientes) {
        archivo << paciente->getID() << ","
            << paciente->getDNI() << ","
            << paciente->getNombre() << ","
            << paciente->getFechaIngreso() << ","
            << (paciente->getHistorial().getDiagnosticosCSV().empty() ? "desconocido" : paciente->getHistorial().getDiagnosticosCSV()) << ","
            << (paciente->getHistorial().getTratamientosCSV().empty() ? "desconocido" : paciente->getHistorial().getTratamientosCSV()) << ","
            << (paciente->getHistorial().getRecetasCSV().empty() ? "desconocido" : paciente->getHistorial().getRecetasCSV()) << ","
            << (paciente->getHistorial().getCirugiasCSV().empty() ? "desconocido" : paciente->getHistorial().getCirugiasCSV()) << "\n";
    }

    archivo.close();
    std::cout << "Pacientes guardados exitosamente en Pacientes.csv." << std::endl;
}

void Gestion::cargarPacientes() {
    std::string archivoPaciente = FileManager::obtenerRutaArchivo("Pacientes.csv");
    std::ifstream archivo(archivoPaciente, std::ios::in);
    if (!archivo.is_open()) {
        std::cerr << archivoPaciente << "no existe o no se puede abrir" << std::endl;
        return;
    }
    pacientes.clear(); 

    std::string linea;
    std::getline(archivo, linea);
    while (std::getline(archivo, linea)) {
        std::istringstream stream(linea);
        std::string id, nombre, dni, fechaIngreso, diagnosticos, tratamientos, recetas, cirugias;;

        getline(stream, id, ',');
        getline(stream, dni, ',');
        getline(stream, nombre, ',');
        getline(stream, fechaIngreso, ',');
        getline(stream, diagnosticos, ',');
        getline(stream, tratamientos, ',');
        getline(stream, recetas, ',');
        getline(stream, cirugias, ',');

        if (recetas.empty())  recetas = "Desconocido";
        if (diagnosticos.empty()) diagnosticos = "Desconocido";
        if (tratamientos.empty()) tratamientos = "Desconocido";
        if (cirugias.empty())  cirugias = "Desconocido";   

        auto it = std::find_if(pacientes.begin(), pacientes.end(), [&id](Paciente* p) {
            return p->getID() == id;
            });
        if (it != pacientes.end()) {
            std::cerr << "El paciente con ID " << id << " ya existe. Saltando...\n";
            continue;
        }  
        try {
            Paciente* nuevoPaciente = new Paciente(nombre, dni, fechaIngreso);
            nuevoPaciente->getHistorial().procesarDiagnosticos(diagnosticos);
            nuevoPaciente->getHistorial().procesarTratamientos(tratamientos);
            nuevoPaciente->getHistorial().procesarRecetas(recetas);
            nuevoPaciente->getHistorial().procesarCirugias(cirugias);
            pacientes.push_back(nuevoPaciente);
        }
        catch (const std::exception& e) {
            std::cerr << "Error al cargar paciente: " << e.what() << ". Saltando registro.\n";
            continue;
        }
    }

    archivo.close();
    std::cout << "Pacientes cargados exitosamente " << archivoPaciente<< "." << std::endl;
}

void Gestion::guardarMedicos() {
    std::string archivoMedico= FileManager::obtenerRutaArchivo("Medicos.csv");
    std::ofstream archivo(archivoMedico, std::ios::out);
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir " << archivoMedico<< "para guardar." << std::endl;
        return;
    }
    archivo << "Nombre,Especialidad,Disponible\n";
    for (const auto& medico : medicos) {
        archivo << medico->getNombre() << ","
                << medico->getEspecialidad() << ","
                <<( medico->isDisponible() ? "1" : "0" )<< "\n";
    }

    archivo.close();
    std::cout << "Medicos guardados exitosamente en Medicos.csv." << std::endl;
}

void Gestion::cargarMedicos() {
    std::string archivoMedico = FileManager::obtenerRutaArchivo("Medicos.csv");
    std::ifstream archivo(archivoMedico, std::ios::in);
    if (!archivo.is_open()) {
        std::cerr << archivoMedico << "no existe o no se puede abrir." << std::endl;
        return;
    }

    std::string linea;
    getline(archivo, linea);
    while (std::getline(archivo, linea)) {
        std::istringstream stream(linea);
        std::string nombre, especialidad;
        bool disponible;

        std::getline(stream, nombre, ',');
        std::getline(stream, especialidad, ',');
        stream >> disponible;

        auto it = std::find_if(medicos.begin(), medicos.end(), [&nombre](Medico* m) {
            return m->getNombre() == nombre;
            });
        if (it != medicos.end()) {
            std::cerr << "El médico con nombre " << nombre << " ya existe. Saltando...\n";
            continue;
        }

        Medico* nuevoMedico = new Medico(nombre, especialidad, disponible == 1);
        medicos.push_back(new Medico(nombre, especialidad, disponible));
    }
    archivo.close();
    std::cout << "Medicos cargados exitosamente desde Medicos.csv." << std::endl;
}

void Gestion::guardarCitas() {
    std::string archivoCita = FileManager::obtenerRutaArchivo("Citas.csv");
    std::ofstream archivo(archivoCita, std::ios::out);
    if (!archivo.is_open()) {
        std::cerr << "Error al abri" << archivoCita << "para guardar." << std::endl;
        return;
    }
    archivo << "Fecha,ID_Paciente,Nombre_Medico\n";
    for (const auto& cita : citas) {
        archivo << cita->getFecha() << ","
                << cita->getPaciente()->getID() << ","
                << cita->getMedico()->getNombre() << "\n";
    }

    archivo.close();
    std::cout << "Citas guardadas exitosamente en Citas.csv." << std::endl;
}

void Gestion::cargarCitas() {
    std::string archivoCita = FileManager::obtenerRutaArchivo("Citas.csv");
    std::ifstream archivo(archivoCita, std::ios::out);
    if (!archivo.is_open()) {
        std::cerr << archivoCita <<"no existe o no se puede abrir." << std::endl;
        return;
    }

    std::string linea;
    getline(archivo, linea);
    while (std::getline(archivo, linea)) {
        std::istringstream stream(linea);
        std::string fecha, hora, idPaciente, nombreMedico;

        std::getline(stream, fecha, ',');
        std::getline(stream, idPaciente, ',');
        std::getline(stream, nombreMedico, ',');

        Paciente* paciente = nullptr;
        Medico* medico = nullptr;

        auto itPaciente = std::find_if(pacientes.begin(), pacientes.end(), [&idPaciente](Paciente* p) {
            return p->getID() == idPaciente;
            });
        if (itPaciente != pacientes.end()) {
            paciente = *itPaciente;
        }
        auto itMedico = std::find_if(medicos.begin(), medicos.end(), [&nombreMedico](Medico* m) {
            return m->getNombre() == nombreMedico;
            });
        if (itMedico != medicos.end()) {
            medico = *itMedico;
        }
        if (paciente && medico) {
            Cita* nuevaCita = new Cita(fecha, paciente, medico);
            citas.push_back(nuevaCita);
        }
    }

    archivo.close();
    std::cout << "Citas cargadas exitosamente desde Citas.csv." << std::endl;
}



