#include "Usuario.hpp"

// DESARROLLO MÉTODOS

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

//GETTERS Y SETTERS ATRIBUTOS
// Getter nombre
string Usuario::get_nombre() const {
    return nombre;
}
// Setter nombre
void Usuario::set_nombre(const string &nom) {
    nombre = nom;
}

// Getter email
string Usuario::get_email() const {
    return email;
}
// Getter email
void Usuario::set_email(const string &em) {
    email = em;
}

// Getter contraseña
string Usuario::get_contrasena() const {
    return contrasena;
}

// Setter contraseña
void Usuario::set_contrasena(const string &pass) {
    contrasena = pass;
}
