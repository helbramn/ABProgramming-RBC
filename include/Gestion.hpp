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
    void registrarPaciente();
    void registrarMedico();
    void agendarCita();
    void consultarHistorial();
};

#endif
