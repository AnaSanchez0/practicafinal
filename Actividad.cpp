
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

 // Getter tíulo
string Actividad::get_titulo() const {
    return titulo;
}
// Setter tíulo
void Actividad::set_titulo(const string &t) {
    titulo = t;
}

// Getter estaCompletada
bool Actividad::get_estaCompletada() const {
    return estaCompletada;
}
// Setter estaCompletada
void Actividad::set_estaCompletada(bool estado) {
    estaCompletada = estado;
}
