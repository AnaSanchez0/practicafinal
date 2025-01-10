#ifndef LISTADETAREAS_HPP
#define LISTADETAREAS_HPP

#include "Tarea.hpp"
#include <vector>
#include <string>

class ListaDeTareas {
private:
    // Creamos una clase vector, para agrupar las tareas en una lista
    vector<Tarea*> tareas;

public:
    // Declaración de los métodos que vamos a desarrollar
    void agregarTarea(Tarea* tarea);
    void eliminarTarea(const string &titulo);
    void mostrarTareas() const;
    void cargarDesdeArchivo(const string &nombreArchivo);
    void guardarEnArchivo(const string &nombreArchivo) const;
    ~ListaDeTareas();
};

#endif
