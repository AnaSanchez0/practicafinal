#ifndef TAREA_HPP
#define TAREA_HPP

#include "Actividad.hpp"

class Tarea : public Actividad {
private:
    string fechaLimite;
    string descripcion;

public:
    Tarea(const string &t, const string &f, const string &d);
    void mostrar() const override;

    string get_fechaLimite() const;
    void set_fechaLimite(const string &f);
    string get_descripcion() const;
    void set_descripcion(const string &d);
};

#endif
