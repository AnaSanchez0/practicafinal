#ifndef LISTADETAREAS_HPP
#define LISTADETAREAS_HPP

#include "Tarea.hpp"
#include <vector>

class ListaDeTareas {
private:
    vector<Tarea*> tareas;

public:
    ~ListaDeTareas();

    void agregarTarea(Tarea* tarea);
    void eliminarTarea(const string &titulo);
    void mostrarTareas() const;
    void cargarDesdeArchivo(const string &nombreArchivo);
    void guardarEnArchivo(const string &nombreArchivo) const;
};

#endif
