#include "ListaDeTareas.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

ListaDeTareas::~ListaDeTareas() {
    for (Tarea* tarea : tareas) {
        delete tarea;
    }
}

void ListaDeTareas::agregarTarea(Tarea* tarea) {
    tareas.push_back(tarea);
}

void ListaDeTareas::eliminarTarea(const string &titulo) {
    for (auto it = tareas.begin(); it != tareas.end(); ++it) {
        if ((*it)->get_titulo() == titulo) {
            delete *it;
            tareas.erase(it);
            cout << "Se ha eliminado la tarea: " << titulo << endl;
            return;
        }
    }
    throw runtime_error("Tarea no encontrada");
}

void ListaDeTareas::mostrarTareas() const {
    if (tareas.empty()) {
        cout << "No hay tareas en la lista" << endl;
        return;
    }
    cout << "LISTA DE TAREAS:\n";
    for (size_t i = 0; i < tareas.size(); ++i) {
        cout << "Tarea " << (i + 1) << ":\n";
        tareas[i]->mostrar();
        cout << "-----------------------" << endl;
    }
}

void ListaDeTareas::cargarDesdeArchivo(const string &nombreArchivo) {
    for (Tarea* tarea : tareas) {
        delete tarea;
    }
    tareas.clear();

    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        throw runtime_error("No se pudo abrir el archivo");
    }

    string titulo, fecha, descripcion;
    while (getline(archivo, titulo, ',') && getline(archivo, fecha, ',') && getline(archivo, descripcion)) {
        if (!titulo.empty()) {
            Tarea* tarea = new Tarea(titulo, fecha, descripcion);
            agregarTarea(tarea);
        }
    }
    archivo.close();
}

void ListaDeTareas::guardarEnArchivo(const string &nombreArchivo) const {
    ofstream archivo(nombreArchivo, ios::out);
    if (!archivo.is_open()) {
        throw runtime_error("No se pudo abrir el archivo");
    }

    for (const Tarea* tarea : tareas) {
        archivo << tarea->get_titulo() << "," << tarea->get_fechaLimite() << "," << tarea->get_descripcion() << endl;
    }
    archivo.close();
}
