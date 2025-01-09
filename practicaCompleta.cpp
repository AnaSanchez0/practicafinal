/*
    Práctica Proyectos de Programación - 1ª entrega
    Alfonso Mora, Ana Sánchez, Anaïs Soler y Claudia García
    Sistema para la gestión y organización de tareas
*/

// Librerías necesarias
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>

using namespace std;

// Creamos una clase abstracta de la que van a derivar las tareas
class Actividad {
protected:
    string titulo;        
    bool estaCompletada;      

public:
    // Constructor
    Actividad(string tit) {
        titulo = tit;

        // Inicializamos como no completada
        estaCompletada = false;
    }

    // Destrucutor virtual para eliminar subclases
    virtual  ~Actividad() {}

    // Método virtual que hace la clase abstracta
    virtual void mostrar() const = 0;

    // Método que marca la actividad como completada
    void completar() {
        estaCompletada = true;
    }

    // Getters y setters de tíulo
    string get_titulo() const {
        return titulo;
    }
    void set_titulo(string t) {
        titulo = t;
    }

    // Getters y setters de estaCompletada
    bool get_estaCompletada() const {
        return estaCompletada;
    }
    void set_estaCompletada(bool estado) {
        estaCompletada = estado;
    }
};

// Clase para las tareas, herencia de Actividad
class Tarea : public Actividad {
private:
    string fechaLimite, descripcion;    

public:
    // Constructor
    Tarea(const string& t, const string& f, const string& d) : Actividad(t) {
        fechaLimite = f;
        descripcion = d;
    }

    // Redefinimos el método que era virtual, muestra la información de la tarea
    void mostrar() const override{
        cout << "Titulo: " << get_titulo()   
            << "\nCompletada: " << (get_estaCompletada() ? "SI" : "NO") 
            << "\nDescripcion: " << descripcion
            << "\nFecha limite: " << fechaLimite
            << endl;
    }

    // Getters y setters de fecha limite
    string get_fechaLimite() const {
        return fechaLimite;
    }
    void set_fechaLimite(const string& f) {
        fechaLimite = f;
    }

    // Getters y setters de descripción
    string get_descripcion() const {
        return descripcion;
    }
    void set_descripcion(const string& d) {
        descripcion = d;
    }
};

// Creamos una clase vector, para agrupar las tareas en una lista
class ListaDeTareas {
private:
    vector<Tarea*> tareas;  

public:
    // Método para añadir una tarea a la lista
    void agregarTarea(Tarea* tarea) {
        tareas.push_back(tarea);
    }

    // Método para eliminar una tarea de la lista 
    void eliminarTarea(const string& titulo) {
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
    void mostrarTareas() const {
        // Si no hay tareas en el vector, mandamos un mensaje
        if (tareas.empty()) {
            cout << "No hay tareas en la lista" << endl;
            return;
        }
        
        // Si hay tareas en el vector, las mostramos
        cout << "LISTA DE TAREAS:\n";

        // Recorremos todo el vector con un bucle for
        for (int i = 0; i < tareas.size(); i++) {
            // Numeramos cada tarea
            cout << "Tarea " << (i + 1) << ":\n";

            // Usamos el método mostrar de la clase Tarea
            tareas[i]->mostrar(); 

            // Separador entre tareas
            cout << "-----------------------" << endl;
        }
    }

    // Método para añadir las tareas desde un archivo
    void cargarDesdeArchivo(const string &nombreArchivo) {
        // Liberamos memoria antes de cargar el archivo
        for (Tarea* tarea : tareas) {
            delete tarea; 
        }
        tareas.clear(); 
            
        // Abrimos el archivo para lectura
        ifstream archivo(nombreArchivo); 

        // Verificamos si el archivo se abrió correctamente
        if (!archivo.is_open()) {  
            // Mostramos un error si no se puede abrir
            throw runtime_error("No se puedo abrir el archivo");
        }

         // Declaramos variables para almacenar los atributos
        string titulo, fecha, descripcion;

        // Usamos getline para leer línea por línea
        while (getline(archivo, titulo, ',') && 
            getline(archivo, fecha, ',') && 
            getline(archivo, descripcion)) {

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
    void guardarEnArchivo(const string &nombreArchivo) const {
        // Abrimos el archivo para escritura
        ofstream archivo(nombreArchivo, ios::out); 

        // Verificamos si el archivo se abrió correctamente
        if (!archivo.is_open()) {  
            // Mostramos un error si no se puede abrir
            throw runtime_error("No se puedo abrir el archivo");
        }

        // Utilizamos un bucle for para escribir de una en una las tareas
        for (const Tarea* tarea : tareas) {
            archivo << tarea->get_titulo() << "," << tarea->get_fechaLimite() << 
            "," << tarea->get_descripcion() << endl;
        }


        // Cerramos el archivo
        archivo.close();  
    }

    // Destructor, para la memoria del vector
    ~ListaDeTareas() {
        for (Tarea* tarea : tareas) {
            delete tarea;
        }
    }
};

// Clase para el usuario
class Usuario {
private:
    string nombre, email, contrasena;       
    ListaDeTareas listaDeTareas;  

public:
    // Constructor 
    Usuario(string nom, string em, string pass) {
        nombre = nom;
        email = em;
        contrasena = pass;
    }

    // Método para obtener la lista de tareas
    ListaDeTareas& obtenerListaDeTareas() { 
        return listaDeTareas; 
    }

    // Método para iniciar sesión
    bool iniciarSesion(const string &em, const string &pass) const {
        // Comprueba que coinciden las credenciales
        return email == em && contrasena == pass; 
    }

    // Getter y setter del nombre
    string get_nombre() const {
        return nombre;
    }
    void set_nombre(string nom) {
        nombre = nom;
    }

    // Getter y setter del email
    string get_email() const {
        return email;
    }
    void set_email(string em) {
        email = em;
    }

    // Getter y setter de la contraseña
    string get_contrasena() const {
        return contrasena;
    }
    void set_contrasena(string pass) {
        contrasena = pass;
    }
};

// Menú de inicio
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
