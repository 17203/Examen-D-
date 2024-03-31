#ifndef user
#define user
#include "base.h"
class Usuario : public base{
public:
int edad;
string nacionalidad;
vector<Usuario*> amigos;
vector <publicacion*> publicaciones;

int getid(){
    return id;
};
void mostrar(){};
void mostrarAmigos();
void mostrarPublicaciones();
void agregarAmigo(Usuario* nuevoAmigo);
};
#endif
/*
Usuario:
Propiedades privadas:
id (int)
Propiedades públicas:
nombre (string) edad (int)
nacionalidad (string)
amigos (vector de tipo Usuario*)
publicaciones (vector de tipo Publicacion*)
Métodos públicos:
int getid:
Regresa el id del Usuario.
void mostrar
Muestra los datos del usuario, incluyendo el ID del usuario. void mostrarAmigos
Muestra una lista de todos los amigos del usuario.
void mostrarPublicaciones
Muestra todas las publicaciones que ha hecho el usuario.
void agregarAmigo (Usuario* nuevoAmigo)
Agrega un usuario existente de la Red Social como amigo.
Al agregar un Usuario como amigo, ambos Usuarios se vuelven amigos, es decir Usuario A está en la lista de amigos de Usuario By Usuario B está en la lista de amigos del Usuario A
void crearPublicacion
Crea una nueva publicación para el usuario.
Crea la publicación directamente desde el método y agrega el apuntador de la publicación al listado de publicaciones del usuario.
Usuario* getAmigo(int id)
Regresa un apuntador al amigo con el id utilizado.
En caso de no encontrar un amigo con ese Id, se debe regresar nullptr y mostrar que no existe un amigo con ese Id.
Constructores:
Usuario(string nombre)
Crea un usuario con el nombre indicado.
Usuario (string nombre, int edad)
Crea un usuario con el nombre y edad indicados.
Usuario (string nombre, int edad, string nacionalidad)
Crea un usuario con el nombre, edad y nacionalidad indicados.*/