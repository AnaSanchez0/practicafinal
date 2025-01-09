#ifndef ACTIVIDAD_HPP
#define ACTIVIDAD_HPP

#include <string>
using namespace std;

class Actividad {
protected:
    string titulo;
    bool estaCompletada;

public:
    Actividad(const string &tit);
    virtual ~Actividad();

    virtual void mostrar() const = 0;
    void completar();

    string get_titulo() const;
    void set_titulo(const string &t);
    bool get_estaCompletada() const;
    void set_estaCompletada(bool estado);
};

#endif
