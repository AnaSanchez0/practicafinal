#include "Tarea.hpp"
#include <iostream>
using namespace std;

Tarea::Tarea(const string &t, const string &f, const string &d) : Actividad(t), fechaLimite(f), descripcion(d) {}

void Tarea::mostrar() const {
    cout << "Titulo: " << get_titulo()
         << "\nCompletada: " << (get_estaCompletada() ? "SI" : "NO")
         << "\nDescripcion: " << descripcion
         << "\nFecha limite: " << fechaLimite
         << endl;
}

string Tarea::get_fechaLimite() const {
    return fechaLimite;
}

void Tarea::set_fechaLimite(const string &f) {
    fechaLimite = f;
}

string Tarea::get_descripcion() const {
    return descripcion;
}

void Tarea::set_descripcion(const string &d) {
    descripcion = d;
}
