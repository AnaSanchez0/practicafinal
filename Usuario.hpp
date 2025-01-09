#ifndef USUARIO_HPP
#define USUARIO_HPP

#include "ListaDeTareas.hpp"

class Usuario {
private:
    string nombre;
    string email;
    string contrasena;
    ListaDeTareas listaDeTareas;

public:
    Usuario(const string &nom, const string &em, const string &pass);

    ListaDeTareas& obtenerListaDeTareas();
    bool iniciarSesion(const string &em, const string &pass) const;

    string get_nombre() const;
    void set_nombre(const string &nom);
    string get_email() const;
    void set_email(const string &em);
    string get_contrasena() const;
    void set_contrasena(const string &pass);
};

#endif
