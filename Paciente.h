#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>     // Para usar std::string

class Paciente {
public:
    // Constructor
    Paciente(const std::string& nombre);
    void mostrarNombre() const; // Método para mostrar el nombre del paciente

private:
    std::string nombre; // Almacena el nombre del paciente
};

#endif // PACIENTE_H#pragma once
