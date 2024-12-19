#ifndef GESTION_HPP
#define GESTION_HPP

#include <vector>
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
    void guardarDatos();
    void cargarDatos();
    void reportePacientesPorFecha(const std::string& fechaInicio, const std::string& fechaFin);
    void reporteCitasPorEspecialidad(const std::string& especialidad);
    void ordenarCitasPorFecha();
};

#endif
