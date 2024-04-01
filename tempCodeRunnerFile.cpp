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

RedSocial rs("paxinc");
    Usuario* usuario1 = new Usuario("Usuario1", 25, "Pais1");
    Usuario* usuario2 = new Usuario("Usuario2", 30, "Pais2");
    rs.agregarUsuario(usuario1);
    rs.agregarUsuario(usuario2);

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
case 1:
    rs.mostrarUsuarios();
break;
  case 2: 
    rs.mostrarPublicaciones();
  break;
case 3:
  int variable=0;
  cout << "introduzca el id del usuario al que desea entrar" <<endl;
  cin >> variable;
  rs.getUsuario(variable);
break;
case 4:

    rs.agregarUsuario();
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
  fecha = fech;
  contenido = cont;
  usuario = usu;
  
}

void Publicacion::mostrarPublicacion(){
cout <<"publicado en: "<< fecha << endl;
cout << contenido<< endl;
cout <<"publicado por: " <<  usuario->nombre<<endl;
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
void Usuario::crearPublicacion(){//no terminado
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

RedSocial::RedSocial(string nombre){
this->nombre= nombre;
}
RedSocial::RedSocial(string nombre,  vector<Usuario*> usuarios):RedSocial(nombre){
//Crea una red social con nombre y una lista precargada de usuarios.
this->usuarios = usuarios;
} 
RedSocial::RedSocial(string nombre, vector<Usuario*> usuarios, vector<Publicacion*> publicaciones):RedSocial(nombre, usuarios){
this->publicaciones = publicaciones;
} 
void RedSocial::agregarUsuario(){//incompleto
  Usuario* us;
  usuarios.push_back(us);

}

void RedSocial::mostrarUsuarios(){
  cout << "existen: " <<numeroDeUsuarios <<" usuarios en la red social actualmente"<<endl;
  cout<<"los cuales son:" << endl;
  for (int i; i<=usuarios.size(); i++){
      cout << usuarios[i]->nombre <<endl;
    }
}
void RedSocial::mostrarPublicaciones(){
  cout << "existen: " <<numeroDePublicaciones <<" publicaciones en la red social actualmente"<<endl;
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