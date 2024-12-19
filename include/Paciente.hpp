#ifndef PACIENTE_HPP
#define PACIENTE_HPP

#include <string>
#include "HistorialClinico.hpp"

class Paciente {
private:
    std::string nombre;
    std::string id;
    std::string fechaIngreso;
    HistorialClinico historial;

public:
    Paciente(const std::string& nombre, const std::string& id, const std::string& fechaIngreso);
    const std::string& getID() const;
    void registrarDiagnostico(const std::string& diagnostico);
    void consultarHistorial() const;
};

#endif

