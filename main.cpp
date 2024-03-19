#include <bits/stdc++.h>
using namespace std;


class Usuario{
int id;
public:
string nombre;
int edad;
string nacionalidad;
vector<Usuario*> amigos;
vector <publicacion*> publicaciones;

int getid();
void mostrar();
void mostrarAmigos();
void mostrarPublicaciones();
void agregarAmigo(Usuario* nuevoAmigo);

 class RedSocial{
    private:
    vector <Usuario> usuarios;
    vector <Publicacion> publicaciones;

    public:
    string nombre;
    int numeroDeUsuarios;
    int numeroDePublicaciones;
    
    RedSocial(); 
    RedSocial(string nom, int nu, int np);
    
    void agregarUsuario();
    void mostrarUsuario();
    void mostrarPublicacion();
    Usuario* getUsuario (int id);
    
/*Métodos públicos:
int getid
Regresa el id del Usuario.
void mostrar
Muestra los datos del usuario, incluyendo el ID del usuario.
void mostrarAmigos
Muestra una lista de todos los amigos del usuario.
void mostrarPublicaciones
■Muestra todas las publicaciones que ha hecho el usuario.
void agregarAmigo (Usuario* nuevoAmigo)
Agrega un usuario existente de la Red Social como amigo.
■ Al agregar un Usuario como amigo, ambos Usuarios se vuelven amigos, es decir Usuario A está en la lista de amigos de Usuario B y Usuario B está en la lista de amigos del Usuario A
void crearPublicacion
Crea una nueva publicación para el usuario.
■ Crea la publicación directamente desde el método y agrega el apuntador de la publicación al listado de publicaciones del usuario.
Usuario* getAmigo(int id)*/
}


int main(){
  

};

  return 0;
}

/*REQUISITOS:
CLASES:
Constructores:
Publicacion:
Regresa un apuntador al amigo con el id utilizado.
En caso de no encontrar un amigo con ese Id, se debe regresar nullptr y mostrar que no existe un amigo con ese Id.
Usuario(string nombre)
Crea un usuario con el nombre indicado.
Usuario (string nombre, int edad)
Crea un usuario con el nombre y edad indicados.
Usuario (string nombre, int edad, string nacionalidad)
Crea un usuario con el nombre, edad y nacionalidad indicados.
Propiedades privadas:
id (int)
Propiedades públicas:
fecha (string)
Contenido (string) Usuario* usuario.
Métodos públicos:
void mostrarPublicacion
■ Muestra la fecha en la que se creó la publicación, su contenido y el nombre del usuario que creó la publicación. Constructores:
Publicacion (Usuario* usuario, string fecha, string contenido)
· Crea una publicación con la fecha, contenido y usuario asignado.INTERFAZ
Opciones de Menú Principal:
Muestra un mensaje de bienvenida a la Red Social y muestra un menú con las siguientes opciones:
·
·
Ver lista de usuarios.
•
Muestra un listado de todos los usuarios que existen en la red social.
Ver lista de publicaciones.
• Muestra un listado de todas las publicaciones que existen en la red social. Entrar a un perfil de usuario.
Salir
O
Se introduce el ID del usuario para identificar al usuario y se muestra el Menú de Usuario en caso de encontrar una coincidencia.
⚫ Cierra el programa.
Opciones de Menú de Usuario.
Al inicio de la pantalla, muestra los datos del usuario seleccionado y un menú con las siguientes opciones:
Ver lista de amigos.
Muestra un listado de todos los amigos que tiene el usuario.
·
Ver publicaciones.
Muestra un listado de todas las publicaciones que ha hecho el usuario.
·
·
·
Crear publicacion.
• Permite crear una nueva publicación.
Entrar a perfil de amigo.
O
Se introduce el ID del amigo para identificarlo y se muestra el Menú de Usuario del amigo seleccionado.
Salir.
.
Regresa al menú de la Red Social.*/
