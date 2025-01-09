#include "Usuario.hpp"

Usuario::Usuario(const string &nom, const string &em, const string &pass)
    : nombre(nom), email(em), contrasena(pass) {}

ListaDeTareas& Usuario::obtenerListaDeTareas() {
    return listaDeTareas;
}

bool Usuario::iniciarSesion(const string &em, const string &pass) const {
    return email == em && contrasena == pass;
}

string Usuario::get_nombre() const {
    return nombre;
}

void Usuario::set_nombre(const string &nom) {
    nombre = nom;
}

string Usuario::get_email() const {
    return email;
}

void Usuario::set_email(const string &em) {
    email = em;
}

string Usuario::get_contrasena() const {
    return contrasena;
}

void Usuario::set_contrasena(const string &pass) {
    contrasena = pass;
}
