#ifndef GESTION_HPP
#define GESTION_HPP

#include <vector>
#include <string>
#include "Paciente.hpp"
#include "Medico.hpp"
#include "Cita.hpp"

class Gestion {
private:
    std::vector<Paciente*> pacientes;
    std::vector<Medico*> medicos;
    std::vector<Cita*> citas;
    std::vector<Paciente> listaPacientes;

    void guardarPacientes();
    void cargarPacientes();
    void guardarMedicos();
    void cargarMedicos();
    void guardarCitas();
    void cargarCitas();

public:
    Gestion();
    ~Gestion();
    void registrarPaciente();
    void registrarMedico();
    void agendarCita();
    void consultarHistorial(const std::string& idPaciente);
    void generarReporte(const std::string& tipo); 
    void guardarEnArchivo(); 
    void cargarDesdeArchivo(); 
    const std::vector<Paciente*>& getPacientes() const;
};

#endif
