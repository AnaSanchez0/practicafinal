#include "Actividad.hpp"

Actividad::Actividad(const string &tit) : titulo(tit), estaCompletada(false) {}

Actividad::~Actividad() {}

void Actividad::completar() {
    estaCompletada = true;
}

string Actividad::get_titulo() const {
    return titulo;
}

void Actividad::set_titulo(const string &t) {
    titulo = t;
}

bool Actividad::get_estaCompletada() const {
    return estaCompletada;
}

void Actividad::set_estaCompletada(bool estado) {
    estaCompletada = estado;
}
