#include "ListaDeTareas.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

// Desarrollo de los métodos

// Método para añadir una tarea a la lista
void ListaDeTareas::agregarTarea(Tarea* tarea) {
    tareas.push_back(tarea);
}

// Método para eliminar una tarea de la lista 
void ListaDeTareas::eliminarTarea(const string &titulo) {
    // Recorremos todo el vector con un bucle for
    for (auto it = tareas.begin(); it != tareas.end(); it++) {
        // Buscamos la tarea por el tíulo
        if ((*it)->get_titulo() == titulo) {
            // Borramos la información de la tarea
            delete *it;

            // Eliminamos la tarea del vector 
            tareas.erase(it);

            // Mostramos un mensjae confirmando que se ha eliminado
            cout << "Se ha eliminado la tarea: " << titulo << endl;

            // Salimos del bucle
            return;
        }
    }

    // Mostramos un error si no encontramos la tarea
    throw runtime_error("Tarea no encontrada");
}
// Método para mostrar todas las tareas de la lista
void ListaDeTareas::mostrarTareas() const {
    // Si no hay tareas en el vector, mandamos un mensaje
    if (tareas.empty()) {
        cout << "No hay tareas en la lista" << endl;
        return;
    }

    // Si hay tareas en el vector, las mostramos
    cout << "LISTA DE TAREAS:\n";

    // Recorremos todo el vector con un bucle for
    for (size_t i = 0; i < tareas.size(); i++) {
        // Numeramos cada tarea
        cout << "Tarea " << (i + 1) << ":\n";

        // Usamos el método mostrar de la clase Tarea
        tareas[i]->mostrar();
        
        // Separador entre tareas
        cout << "-----------------------" << endl;
    }
}

 // Método para añadir las tareas desde un archivo
void ListaDeTareas::cargarDesdeArchivo(const string &nombreArchivo) {
    // Liberamos memoria antes de cargar el archivo
    for (Tarea* tarea : tareas) {
        delete tarea;
    }
    tareas.clear();

    // Verificamos si el archivo se abrió correctamente
    ifstream archivo(nombreArchivo);
    
    if (!archivo.is_open()) {
        // Mostramos un error si no se puede abrir
        throw runtime_error("No se pudo abrir el archivo");
    }
    
    // Declaramos variables para almacenar los atributos
    string titulo, fecha, descripcion;

    // Usamos getline para leer línea por línea
    while (getline(archivo, titulo, ',') && getline(archivo, fecha, ',') && getline(archivo, descripcion)) {
         // Comprobamos si el título no está vacío 
        if (!titulo.empty()) {
            // Creamos una nueva tarea y la agregamos a la lista
            Tarea* tarea = new Tarea(titulo, fecha, descripcion);
            agregarTarea(tarea);
        }
    }

    // Cerramos el archivo
    archivo.close();
}

// Método para guardar las tareas en un archivo
void ListaDeTareas::guardarEnArchivo(const string &nombreArchivo) const {
    // Abrimos el archivo para escritura
    ofstream archivo(nombreArchivo, ios::out);

    // Verificamos si el archivo se abrió correctamente
    if (!archivo.is_open()) {
        // Mostramos un error si no se puede abrir
        throw runtime_error("No se pudo abrir el archivo");
    }

     // Utilizamos un bucle for para escribir de una en una las tareas
    for (const Tarea* tarea : tareas) {
        archivo << tarea->get_titulo() << "," << tarea->get_fechaLimite() << "," << tarea->get_descripcion() << endl;
    }
    
    // Cerramos el archivo
    archivo.close();
}

// Destructor, para la memoria del vector
ListaDeTareas::~ListaDeTareas() {
    for (Tarea* tarea : tareas) {
        delete tarea;
    }
}
