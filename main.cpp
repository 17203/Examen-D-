#include "usuario.h"
#include "RedSocial.h"
#include "Publicacion.h"
#include <bits/stdc++.h>
using namespace std;

int getid();
void mostrar();
void mostrarAmigos();
void mostrarPublicaciones();
void agregarAmigo(Usuario* nuevoAmigo);

int a;
int main(){
  
cout << "bienvenido" <<endl;
cout << "presione 1 para ver lista de usuarios." << endl;
cout << "presione 2 para ver lista de publicaciones." << endl;
cout << "presione 3 para entrar a un perfil de usuario." << endl;
cout << "presione 4 para agregar un nuevo usuario." << endl;
cout << "presione 5 para salir" << endl;

while (a != 0){
switch(a){
case 1:
    //mostrara lista de usuarios
break;
  case 2: 
    //mostrara lista de publicaciones
  break;
case 3:

break;
case 4:

break;
case 5:
  return 0;
break;
}

}
  return 0;
}
/*INTERFAZ
Opciones de Menú Principal:
Muestra un mensaje de bienvenida a la Red Social y muestra un menú con las siguientes opciones:
Ver lista de usuarios.
Muestra un listado de todos los usuarios que existen en la red social.
Ver lista de publicaciones.
Muestra un listado de todas las publicaciones que existen en la red social. 
Entrar a un perfil de usuario.
Se introduce el ID del usuario para identificar al usuario y se muestra el Menú de Usuario en caso de encontrar una coincidencia.
Agregar un nuevo usuario.
Se piden los datos del nuevo usuario y se crea.
Se agrega a la lista de usuarios de la red social.
Salir
Cierra el programa.
Opciones de Menú de Usuario.
Al inicio de la pantalla, muestra los datos del usuario seleccionado y un menú con las siguientes opciones:
Ver lista de amigos.
Muestra un listado de todos los amigos que tiene el usuario.
Ver publicaciones.
Muestra un listado de todas las publicaciones que ha hecho el usuario.
Crear publicacion.
Permite crear una nueva publicación.
Entrar a perfil de amigo.
Se introduce el ID del amigo para identificarlo y se muestra el Menú de Usuario del amigo seleccionado. Agregar un nuevo amigo.
Salir.
Se muestra la lista de los usuarios que existen, se introduce el ID y se hacen amigos.
Regresa al menú de la Red Social.*/