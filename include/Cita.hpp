#ifndef CITA_HPP
#define CITA_HPP

#include <string>
#include "Paciente.hpp"
#include "Medico.hpp"

class Cita {
private:
    std::string fecha;
    std::string hora;
    Paciente* paciente;
    Medico* medico;

public:
    Cita(const std::string& fecha, const std::string& hora, Paciente* paciente, Medico* medico);
    void mostrarCita() const;
};

#endif