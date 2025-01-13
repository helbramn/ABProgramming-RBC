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

public:
    Gestion();
    ~Gestion();
    void registrarPaciente();
    void registrarMedico();
    void agendarCita();
    void consultarHistorial(const std::string& idPaciente);
    void generarReporte(const std::string& tipo); 
    const std::vector<Paciente*>& getPacientes() const;
    bool validarFecha(const std::string& fecha);


    void guardarPacientes();
    void cargarPacientes();
    void guardarMedicos();
    void cargarMedicos();
    void guardarCitas();
    void cargarCitas();
};

#endif
