#ifndef TAREA_HPP
#define TAREA_HPP

#include "Actividad.hpp"
#include <string>

// Clase para las tareas, herencia de Actividad
class Tarea : public Actividad {
private:
    string fechaLimite;
    string descripcion;

public:
    // Declaración de los métodos que vamos a desarrollar
    Tarea(const string &t, const string &f, const string &d);
    void mostrar() const override;
    string get_fechaLimite() const;
    void set_fechaLimite(const string &f);
    string get_descripcion() const;
    void set_descripcion(const string &d);
};

#endif
