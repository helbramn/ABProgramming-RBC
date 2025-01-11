#ifndef CITA_HPP
#define CITA_HPP

#include <string>
#include "Paciente.hpp"
#include "Medico.hpp"

class Cita {
private:
    std::string fecha;
    Paciente* paciente;
    Medico* medico;

public:
    Cita(const std::string& fecha, Paciente* paciente, Medico* medico);
    std::string getFecha() const;
    Paciente* getPaciente() const;
    Medico* getMedico() const;
    void mostrarCita() const;
    bool cancelarCita();
    void modificarCita();
    static void ordenarCitasPorFecha(std::vector<Cita*>& citas);


};

#endif