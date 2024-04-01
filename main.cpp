#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Usuario;
int id;
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
    Usuario(string nombr, int ed, string nac);

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
    
    RedSocial(string nombre); //Crea una red social con el nombre asignado.
    RedSocial(string nombre,  vector<Usuario*> usuarios); //Crea una red social con nombre y una lista precargada de usuarios.
    RedSocial(string nombre, vector<Usuario*> usuarios, vector<Publicacion*> publicaciones); //Crea una red social con nombre y listas precargadas de usuarios y publicaciones.

    void agregarUsuario(); //Permite agregar un usuario a la lista total de usuarios.
    void mostrarUsuarios(); //Muestra todos los usuarios que existen actualmente en la red social.
    void mostrarPublicaciones(); //Muestra todas las publicaciones que existen actualmente en la red social.
    Usuario* getUsuario (int id); //Regresa un apuntador hacia el usuario que tiene el id usado En caso de no encontrar una coincidencia, regresa nullptr y muestra un mensaje diciendo que no existe ese usuario.
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
cout <<"publicado por" <<  usuario->nombre<<endl;
}

Usuario::Usuario(string nom){
  id++;
  this->id=id;
  this->nombre= nom;
  this->edad= 0;
  this->nacionalidad="¿?";
}
Usuario::Usuario(string nom, int ed): Usuario(nom){
  this->edad = ed;
}
Usuario::Usuario(string nom, int ed, string nac): Usuario(nom, ed){
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
      cout << amigos[i]->nombre <<endl;
    }
}
void Usuario::mostrarPublicaciones(){
  for (int i; i<=publicaciones.size(); i++){
      cout << publicaciones[i] <<endl;
    }
}

void Usuario::agregarAmigo(Usuario* nuevoAmigo){
  amigos.push_back(nuevoAmigo);
}
void Usuario::crearPublicacion(){
  Publicacion* np;
  publicaciones.push_back(np);
}
Usuario* Usuario::getAmigo(int id){
  for (int i; i<=amigos.size(); i++){
     if(amigos[i]->id == id){
      return amigos[i];
     }else {
      cout << "no existe ningun amigo con ese id :(" << endl;
      return nullptr;
     }
    }
}

RedSocial::RedSocial(string nombre){ //Crea una red social con el nombre asignado.
this->nombre= nombre;
}
RedSocial::RedSocial(string nombre,  vector<Usuario*> usuarios):RedSocial(nombre){
//Crea una red social con nombre y una lista precargada de usuarios.
this->usuarios = usuarios;
} 
RedSocial::RedSocial(string nombre, vector<Usuario*> usuarios, vector<Publicacion*> publicaciones):RedSocial(nombre, usuarios){//Crea una red social con nombre y listas precargadas de usuarios y publicaciones.
this->publicaciones = publicaciones;
} 
void RedSocial::agregarUsuario(){
  Usuario* us;
  usuarios.push_back(us);

}

void RedSocial::mostrarUsuarios(){
  for (int i; i<=usuarios.size(); i++){
      cout << usuarios[i]->nombre <<endl;
    }
}
void RedSocial::mostrarPublicaciones(){
for (int i; i<=publicaciones.size(); i++){
      cout << publicaciones[i] <<endl;
    }
}
Usuario* RedSocial::getUsuario(int id){
for(int i; i<= usuarios.size(); i++){
  if(usuarios[i]->getid() == id){
  return usuarios[i];
  } else {
  cout << "este usuario no existe" << endl;
  return nullptr;
  }
  }
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