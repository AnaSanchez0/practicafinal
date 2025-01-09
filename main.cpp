#include "Usuario.hpp"
#include <iostream>
using namespace std;

void mostrarMenu(Usuario& usuario);

int main() {
    try {
        Usuario usuario("Ignacio Moreno", "ignacio.moreno@gmail.com", "igm2004");

        string email, contrasena;
        cout << "Iniciar sesion (pruebe ignacio.moreno@gmail.com, igm2004 )\n";
        cout << "Email: ";
        cin >> email;
        cout << "Contrasena: ";
        cin >> contrasena;

        if (!usuario.iniciarSesion(email, contrasena)) {
            cout << "Credenciales incorrectas. Saliendo del programa.\n";
            return 1;
        }

        cout << "Credenciales correctas. Bienvenido, " << usuario.get_nombre() << endl;
        mostrarMenu(usuario);

    } catch (const runtime_error& e) {
        cout << "Ha habido un error: " << e.what() << endl;
    }

    return 0;
}

void mostrarMenu(Usuario& usuario) {
    int opcion;
    do {
        cout << "\n------------ MENU------------\n"
             << "1- Ver lista de tareas\n"
             << "2- Anadir tarea nueva\n"
             << "3- Eliminar tarea\n"
             << "4- Guardar tareas en archivo\n"
             << "5- Cargar tareas desde archivo\n"
             << "6- Salir\n"
             << "Seleccione una opcion: ";

        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                usuario.obtenerListaDeTareas().mostrarTareas();
                break;
            case 2: {
                string titulo, fecha, descripcion;
                cout << "Introduzca el titulo de la tarea: ";
                getline(cin, titulo);
                cout << "Introduzca la fecha limite (DD/MM/AAAA): ";
                getline(cin, fecha);
                cout << "Introduzca la descripcion: ";
                getline(cin, descripcion);

                Tarea* nuevaTarea = new Tarea(titulo, fecha, descripcion);
                usuario.obtenerListaDeTareas().agregarTarea(nuevaTarea);
                cout << "Tarea anadida \n";
                break;
            }
            case 3: {
                string titulo;
                cout << "Introduzca el titulo de la tarea a eliminar: ";
                getline(cin, titulo);
                try {
                    usuario.obtenerListaDeTareas().eliminarTarea(titulo);
                } catch (const runtime_error& e) {
                    cout << "Error: " << e.what() << endl;
                }
                break;
            }
            case 4: {
                string nombreArchivo;
                cout << "Introduzca el nombre del archivo: ";
                cin >> nombreArchivo;
                try {
                    usuario.obtenerListaDeTareas().guardarEnArchivo(nombreArchivo);
                    cout << "Tareas guardadas con exito.\n";
                } catch (const runtime_error& e) {
                    cout << "Error: " << e.what() << endl;
                }
                break;
            }
            case 5: {
                string nombreArchivo;
                cout << "Introduzca el nombre del archivo: ";
                cin >> nombreArchivo;
                try {
                    usuario.obtenerListaDeTareas().cargarDesdeArchivo(nombreArchivo);
                    cout << "Tareas cargadas con exito.\n";
                } catch (const runtime_error& e) {
                    cout << "Error: " << e.what() << endl;
                }
                break;
            }
            case 6:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion no valida.\n";
                break;
        }
    } while (opcion != 6);
}
