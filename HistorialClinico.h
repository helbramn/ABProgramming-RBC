#pragma once
#ifndef HISTORIAL_CLINICO_H
#define HISTORIAL_CLINICO_H

#include <string>     // Para usar std::string
#include <vector>     // Para usar std::vector

class HistorialClinico {
public:
    // Métodos de la clase HistorialClinico
    void agregarRegistro(const std::string& registro);
    void mostrarRegistros() const;

private:
    std::vector<std::string> registros; // Almacena los registros
};

#endif // HISTORIAL_CLINICO_H