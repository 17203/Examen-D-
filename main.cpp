#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Usuario;
class Publicacion{
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
  static int numId;
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
int Usuario::numId=0;
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

    void agregarUsuario(Usuario* nuevo); //Permite agregar un usuario a la lista total de usuarios.
    void mostrarUsuarios(); //Muestra todos los usuarios que existen actualmente en la red social.
    void mostrarPublicaciones(); //Muestra todas las publicaciones que existen actualmente en la red social.
    Usuario* getUsuario (int id); //Regresa un apuntador hacia el usuario que tiene el id usado En caso de no encontrar una coincidencia, regresa nullptr y muestra un mensaje diciendo que no existe ese usuario.
};
RedSocial rs("paxinc");
void menuDeUsuario(Usuario* usuario);
void login(int variable);


//menu es medianamente funcional
int main(){
    Usuario* usuario1 = new Usuario("juante", 25, "brazil");
    Usuario* usuario2 = new Usuario("Brayan", 30, "polanco");
    rs.agregarUsuario(usuario1);
    rs.agregarUsuario(usuario2);
menuPrincipal:
int seleccion=8;
while (seleccion != 0){
cout << "Bienvenido" <<endl;
cout << "presione 1 para ver lista de usuarios." << endl;
cout << "presione 2 para ver lista de publicaciones." << endl;
cout << "presione 3 para entrar a un perfil de usuario." << endl;
cout << "presione 4 para agregar un nuevo usuario." << endl;
cout << "presione 5 para salir" << endl;
cin >> seleccion;
switch(seleccion){
case 1:
{ system("cls");
  rs.mostrarUsuarios();}
break;
  case 2: 
{ system("cls");
  rs.mostrarPublicaciones();}
  break;
case 3:
{int variable=0;
  cout << "introduzca el id del usuario al que desea entrar" <<endl;
  cin >> variable;
  login(variable);
}
break;
case 4:
{  
  system("cls");
  cout << " si desea incluir nacionalidad y edad pulse 1" << endl;
      cout << " si desea incluir edad pulse 2" << endl;
      cout << " si no los desea incluir pulse 3" << endl;
string nom, nac;
int ed, sel;
cin>> sel;
  switch(sel){
    case 1:{
    cout<<"introduzca el nombre del usuario " <<endl;
    cin >> nom;  
    cout << "introduzca la edad del usuario " << endl;
    cin>> ed;
    cout << "introduzca la nacionalidad del usuario " <<endl;
    cin >> nac;
    Usuario* nuevoC = new Usuario(nom,ed, nac);
    rs.agregarUsuario(nuevoC);}
    break;
    case 2:{
    cout<<"introduzca el nombre del usuario " <<endl;
    cin >> nom;  
    cout << "introduzca la edad del usuario " << endl;
    cin>> ed;
    Usuario* nuevoE = new Usuario(nom,ed);
    rs.agregarUsuario(nuevoE);
   } break;
    case 3:{
    cout<<"introduzca el nombre del usuario " <<endl;
    cin >> nom;  
    Usuario* nuevoI = new Usuario(nom);
    rs.agregarUsuario(nuevoI);
   } break;
  }
    }
break;
case 5:
  return 0;
break;
default: 
    cout << "opcion no valida, seleccione una correcta "<< endl;
    break;
}

}
  return 0;
}
void menuDeUsuario(Usuario* usuario){
  system("cls");
  int seleccion=1, var;
  Usuario* amigo;
  usuario->mostrar();


while(seleccion != 0){
cout << "presione 1 para ver lista de amigos." << endl; //Muestra un listado de todos los amigos que tiene el usuario.
cout << "presione 2 para ver las publicaciones." << endl; //Muestra un listado de todas las publicaciones que ha hecho el usuario.
cout << "presione 3 para crear publicacion." << endl;//Permite crear una nueva publicación.
cout << "presione 4 para entrar a perfil de amigo" << endl; //Se introduce el ID del amigo para identificarlo y se muestra el Menú de Usuario del amigo seleccionado.
cout << "presione 5 agregar un nuevo amigo" << endl;//Se muestra la lista de los usuarios que existen, se introduce el ID y se hacen amigos.
cout << "presione 6 volver al mennu principal" << endl;
cin >> seleccion;
  switch(seleccion){
    case 1:
    usuario->mostrarAmigos();
    break;
    case 2:
    usuario->mostrarPublicaciones();
    break;
    case 3:
    usuario->crearPublicacion();
    break;
    case 4:
    cout << "introduzca el ID del perfil de su amigo" <<endl;
    cin>> var;
    login(var);
    break;
    case 5:{
    rs.mostrarUsuarios();
    cout << "introduzca el ID del amigo a agregar" << endl;
    cin>>var;
    Usuario* amigo = rs.getUsuario(var);
    usuario->agregarAmigo(amigo);
   } break;
    case 6:
    return;
    break;
    default: 
    cout << "opcion no valida, seleccione una correcta "<< endl;
    break;
  }
}
}
void login(int variable){
Usuario* us = rs.getUsuario(variable);
  if(us != nullptr)
  menuDeUsuario(us);}


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
  this->id=numId++;
  this->nombre= nom;
  this->edad= 0;
  this->nacionalidad="Racoon city";
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
    for (int i; i<amigos.size(); i++){
      cout << amigos[i]->nombre <<endl;
    }
}
void Usuario::mostrarPublicaciones(){
  for (int i; i<publicaciones.size(); i++){
      cout << publicaciones[i] <<endl;
    }
}

void Usuario::agregarAmigo(Usuario* nuevoAmigo){
  amigos.push_back(nuevoAmigo);
  nuevoAmigo->amigos.push_back(this);
}
void Usuario::crearPublicacion(){//si terminado :D
  Publicacion* np = new Publicacion(this, "", "");
  cout << "introduzca la fecha" <<endl;
  cin >> np->fecha;
  cout << "introduzca el contenido" << endl;
  cin >> np->contenido;
  np->usuario=this;
  publicaciones.push_back(np);
}
Usuario* Usuario::getAmigo(int id){
  for (int i; i<amigos.size(); i++){
     if(amigos[i]->id == id){
      return amigos[i];
     }
     }
      cout << "no existe ningun amigo con ese id :(" << endl;
      return nullptr;

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
void RedSocial::agregarUsuario(Usuario* nuevo){
  numeroDeUsuarios++;
  usuarios.push_back(nuevo);
}

void RedSocial::mostrarUsuarios(){
  cout << "existen: " <<numeroDeUsuarios <<" usuarios en la red social actualmente"<<endl;
  cout<<"los cuales son:" << endl;
  for (int i=0; i<usuarios.size(); i++){
      cout << usuarios[i]->nombre <<"  ID:"<< usuarios[i]->getid() << endl;
    }
}
void RedSocial::mostrarPublicaciones(){
  cout << "existen: " <<numeroDePublicaciones <<" publicaciones en la red social actualmente"<<endl;
for (int i; i<publicaciones.size(); i++){
      cout << publicaciones[i] <<endl;
    }
}
Usuario* RedSocial::getUsuario(int id){
    for(int i = 0; i < usuarios.size(); i++){
        if(usuarios[i]->getid() == id){
            return usuarios[i];
        }
    }
    cout << "este usuario no existe" << endl;
    return nullptr;
}