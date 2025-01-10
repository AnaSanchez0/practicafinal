#include "Usuario.hpp"

// Desarrollo de los métodos

// Constructor
Usuario::Usuario(const string &nom, const string &em, const string &pass)
    : nombre(nom), email(em), contrasena(pass) {}

// Método para obtener la lista de tareas
ListaDeTareas& Usuario::obtenerListaDeTareas() {
    return listaDeTareas;
}

// Método para iniciar sesión
bool Usuario::iniciarSesion(const string &em, const string &pass) const {
    // Comprueba que coinciden las credenciales
    return email == em && contrasena == pass;
}

// Getter y setter del nombre
string Usuario::get_nombre() const {
    return nombre;
}
void Usuario::set_nombre(const string &nom) {
    nombre = nom;
}

// Getter y setter del email
string Usuario::get_email() const {
    return email;
}
void Usuario::set_email(const string &em) {
    email = em;
}

// Getter y setter de la contraseña
string Usuario::get_contrasena() const {
    return contrasena;
}

void Usuario::set_contrasena(const string &pass) {
    contrasena = pass;
}
