#include "Usuario.hpp"
#include <iostream>

using namespace std;

// Declaración de los métodos que vamos a desarrollar
void mostrarMenu(Usuario& usuario);

// Desarrollamos la funcion principal
int main() {
    try {
        // Creamos un usuario
        Usuario usuario("Ignacio Moreno", "ignacio.moreno@gmail.com", "igm2004");

        // Pedmimos al usuario las credenciales para iniciar sesión
        string email, contrasena;
        cout << "Iniciar sesion (pruebe ignacio.moreno@gmail.com, igm2004 )\n";
        cout << "Email: ";
        cin >> email;
        cout << "Contrasena: ";
        cin >> contrasena;

        // Salimos del programa si no coinciden las credenciales
        if (!usuario.iniciarSesion(email, contrasena)) {
            cout << "Credenciales incorrectas. Saliendo del programa.\n";
            return 1;
        }

        // Vamos al menu si las credenciales coinciden
        cout << "Credenciales correctas. Bienvenido, " << usuario.get_nombre() << endl;
        mostrarMenu(usuario);

    } catch (const runtime_error& e) {
        // Mostramos la excepcion en caso de error
        cout << "Ha habido un error: " << e.what() << endl;
    }

    return 0;
}

// Desarrollo del menú de inicio
void mostrarMenu(Usuario& usuario) {
    int opcion;
    do {
        // Mostramos las opciones
        cout << "\n------------ MENU------------\n"
             << "1- Ver lista de tareas\n"
             << "2- Anadir tarea nueva\n"
             << "3- Eliminar tarea\n"
             << "4- Guardar tareas en archivo\n"
             << "5- Cargar tareas desde archivo\n"
             << "6- Salir\n"
             << "Seleccione una opcion: ";

        // El usuario introduce una opción 
        cin >> opcion;

        // Para evitar conflictos con espacios
        cin.ignore();

        // Desarrollamos las posibles opciones
        switch (opcion) {
            case 1: // Ver lista de tareas
                usuario.obtenerListaDeTareas().mostrarTareas();
                break;
            case 2: { // Añadir tarea nueva
                string titulo, fecha, descripcion;

                // Le pedimos al usuario los nuevos datos
                cout << "Introduzca el titulo de la tarea: ";
                getline(cin, titulo);
                cout << "Introduzca la fecha limite (DD/MM/AAAA): ";
                getline(cin, fecha);
                cout << "Introduzca la descripcion: ";
                getline(cin, descripcion);

                // Creamos la tarea con los nuevos datos
                Tarea* nuevaTarea = new Tarea(titulo, fecha, descripcion);

                // Añadimos la nueva tarea  a la lista
                usuario.obtenerListaDeTareas().agregarTarea(nuevaTarea);

                // Mostramos un mensaje de que se ha añadido
                cout << "Tarea anadida \n";
                break;
            }
            case 3: { // Eliminar tarea
                string titulo;

                // Le pedimos al usuario la tarea que quiere eliminar
                cout << "Introduzca el titulo de la tarea a eliminar: ";
                getline(cin, titulo);
                try {
                    // Si existe la tarea se elimina
                    usuario.obtenerListaDeTareas().eliminarTarea(titulo);
                    
                } catch (const runtime_error& e) {
                    // Si no existe mostramos un error
                    cout << "Error: " << e.what() << endl;
                }
                break;
            }
            case 4: { // Guardar tareas en archivo
                string nombreArchivo;

                // Le pedimos al usuario el nombre del archivo
                cout << "Introduzca el nombre del archivo: ";
                cin >> nombreArchivo;
                
                try {
                    // Generamos un archivo con las tareas
                    usuario.obtenerListaDeTareas().guardarEnArchivo(nombreArchivo);
                    cout << "Tareas guardadas con exito.\n";
                    
                } catch (const runtime_error& e) {
                    // Si no es posible mostramos un error
                    cout << "Error: " << e.what() << endl;
                }
                break;
            }
            case 5: { //  Cargar tareas desde archivo
                string nombreArchivo;

                // Le pedimos al usuario el nombre del archivo
                cout << "Introduzca el nombre del archivo: ";
                cin >> nombreArchivo;
                
                try {
                    // Si existe el archivo se cargan las tareas
                    usuario.obtenerListaDeTareas().cargarDesdeArchivo(nombreArchivo);
                    cout << "Tareas cargadas con exito.\n";
                    
                } catch (const runtime_error& e) {
                    // Si no existe mostramos un error
                    cout << "Error: " << e.what() << endl;
                }
                break;
            }
            case 6: // Salir
                cout << "Saliendo...\n";
                break;
            default: // En caso de que no introduzca una de las opciones
                cout << "Opcion no valida.\n";
                break;
        }
    // Se repite mientras no seleccione la opcion de salir 
    } while (opcion != 6);
}
