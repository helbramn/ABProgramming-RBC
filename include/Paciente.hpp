#ifndef PACIENTE_HPP
#define PACIENTE_HPP

#include <string>
#include "HistorialClinico.hpp"

class Paciente {
private:
    std::string nombre;
    std::string dni;
    std::string fechaIngreso;
    HistorialClinico historial;

public:
    Paciente(const std::string& nombre, const std::string& dni, const std::string& fechaIngreso);
    const std::string& getDNI() const;
    void registrarDiagnostico(const std::string& diagnostico);
    void consultarHistorial() const;
};

#endif

