#include "Actividad.hpp"

// Desarrollo de los métodos

// Constructor, inicializamos como no completada
Actividad::Actividad(const string &tit) : titulo(tit), estaCompletada(false) {}

// Destrucutor virtual para eliminar subclases
Actividad::~Actividad() {}

// Método que marca la actividad como completada
void Actividad::completar() {
    estaCompletada = true;
}

 // Getters y setters de tíulo
string Actividad::get_titulo() const {
    return titulo;
}
void Actividad::set_titulo(const string &t) {
    titulo = t;
}

// Getters y setters de estaCompletada
bool Actividad::get_estaCompletada() const {
    return estaCompletada;
}
void Actividad::set_estaCompletada(bool estado) {
    estaCompletada = estado;
}
