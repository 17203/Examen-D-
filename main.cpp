#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Usuario;
class base {
private:
 int id;
public:
string fecha;   
};
class Publicacion/*: public base */{ //ver como agregar herencia de clase base, posible pero algo fallo
private:
int id;
public:
string fecha;
string contenido;
Usuario* usuario;
Publicacion(Usuario* usu, string fech, string cont);
void mostrarPublicacion();
};

class Usuario{
private:
int id;
public:
string nombre;
int edad;
string nacionalidad;
vector<Usuario*> amigos;
vector <Publicacion*> publicaciones;

Usuario(string nom);
Usuario(string nomb, int ed);
Usuario(string nombr, int eda, string nac);

int getid();
void mostrar();
void mostrarAmigos();
void mostrarPublicaciones();
void agregarAmigo(Usuario* nuevoAmigo);
void crearPublicacion();
Usuario* getAmigo(int id);

};

class RedSocial{
    private:
    vector <Usuario*> usuarios;
    vector <Publicacion*> publicaciones;

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
};

//menu sigue sin ser funcional
int main(){
int seleccion;
cout << "bienvenido" <<endl;
cout << "presione 1 para ver lista de usuarios." << endl;
cout << "presione 2 para ver lista de publicaciones." << endl;
cout << "presione 3 para entrar a un perfil de usuario." << endl;
cout << "presione 4 para agregar un nuevo usuario." << endl;
cout << "presione 5 para salir" << endl;
cin >> seleccion;
while (seleccion != 0){
switch(seleccion){
case 1://fallo en primer intento de hacerlo debido a que nno se implementaron los metodos correctos, revisar 
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
//revisar este constructor por el valor de usuario, este se agrega al vector de publicaciones
Publicacion::Publicacion(Usuario* usu, string fech, string cont){
  usuario = usu;
  fecha = fech;
  contenido = cont;
}

void Publicacion::mostrarPublicacion(){
cout << fecha << endl;
cout << contenido<< endl;
Usuario* usuario;
}

Usuario::Usuario(string nom){
  this->nombre= nom;
}
Usuario::Usuario(string nom, int ed){
  this->nombre = nom;
  this->edad = ed;
}
Usuario::Usuario(string nom, int ed, string nac){
  this->nombre = nom;
  this->edad = ed;
  this->nacionalidad = nac;
}

int Usuario::getid(){
    return this->id;
}
void Usuario::mostrar(){
  cout << "hola, soy " << nombre << ", tengo "<< edad << " años y provengo de "<< nacionalidad << endl;
  cout <<"mi identificador es " << this->id << endl;
}
void Usuario::mostrarAmigos(){
    for (int i; i<=amigos.size(); i++){
      cout << amigos[i] <<endl;
    }
}
void Usuario::mostrarPublicaciones(){
  for (int i; i<=publicaciones.size(); i++){
      cout << publicaciones[i] <<endl;
    }
} //agregar a estas instrucciones lo faltante
void Usuario::agregarAmigo(Usuario* nuevoAmigo){}
void Usuario::crearPublicacion(){

 // Publicacion(Usuario* usu, string fech, string cont);
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