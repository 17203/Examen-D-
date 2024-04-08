#include <iostream>
#include <vector>
#include <set>
#include <string>
#include "rlutil.h"
#include "Usuario.h"
#include "Publicacion.h"
#include "RedSocial.h"
using namespace std;
using namespace rlutil;

RedSocial rs("Suave_Spychalski");
void menuDeUsuario(Usuario* usuario);
void login(int variable);
void fresquito();
//menu es funcional
int main(){
    Usuario* usuario1 = new Usuario("carlos", 45, "brazil");
    Usuario* usuario2 = new Usuario("Brayan", 60, "polanco");
    Usuario* usuario3 = new Usuario("Leon_Kennedy");
    rs.agregarUsuario(usuario1);
    rs.agregarUsuario(usuario2);
    rs.agregarUsuario(usuario3);
    rs.categoriaUsuario();
int seleccion=8;
while (seleccion != 0){
cls();
cout << "Bienvenido" <<endl;
cout << "presione 1 para ver lista de usuarios." << endl;
cout << "presione 2 para ver lista de publicaciones." << endl;
cout << "presione 3 para entrar a un perfil de usuario." << endl;
cout << "presione 4 para agregar un nuevo usuario." << endl;
cout << "presione 5 para salir" << endl;
cin >> seleccion;
switch(seleccion){
case 1:
{ cls();
  rs.mostrarUsuarios();
  cout << endl;
  fresquito();
  }
break;
  case 2: 
{ system("cls");
  rs.mostrarPublicaciones();
  fresquito();}
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
    introedad:
    cin>> ed;
    if (ed>13){
    cout << "introduzca la nacionalidad del usuario " <<endl;
    cin >> nac;
    Usuario* nuevoC = new Usuario(nom,ed, nac);
    rs.agregarUsuario(nuevoC);}
    else {cout << "edad no valida, el usuario debe ser mayor a los 13 años" << endl;
    goto introedad;} }
    break;
    case 2:{
    cout<<"introduzca el nombre del usuario, remplaze los espacios por otros caracteres " <<endl;
    cin >> nom;  
    cout << "introduzca la edad del usuario " << endl;
    introedad2:
    cin>> ed;
    if (ed>13){
    Usuario* nuevoE = new Usuario(nom,ed);
    rs.agregarUsuario(nuevoE);}
    else {cout << "edad no valida, el usuario debe ser mayor a los 13 años" << endl;
    goto introedad2;}
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
  int seleccion=0, var;
  Usuario* amigo;
  


while(seleccion != 6){
  usuario->mostrar();
cout << "presione 1 para ver lista de amigos." << endl; //Muestra un listado de todos los amigos que tiene el usuario.
cout << "presione 2 para ver las publicaciones." << endl; //Muestra un listado de todas las publicaciones que ha hecho el usuario.
cout << "presione 3 para crear publicacion." << endl;//Permite crear una nueva publicación.
cout << "presione 4 para entrar a perfil de amigo" << endl; //Se introduce el ID del amigo para identificarlo y se muestra el Menú de Usuario del amigo seleccionado.
cout << "presione 5 agregar un nuevo amigo" << endl;//Se muestra la lista de los usuarios que existen, se introduce el ID y se hacen amigos.
cout << "presione 6 volver al menu principal" << endl;
cout << "presione 7 para probar las sugerencias" << endl;
cin >> seleccion;
  switch(seleccion){
    case 1:
    cls();
  if(usuario->amigos.size()==0){//funcion no sirve, no enseña amigos
      cout<< "jajajaja no tienes amigos loser" << endl;
    }else{
    cout << "Amigos: " << endl;
    usuario->mostrarAmigos(); 
    }
    fresquito();
    break;
    case 2:
    cls();
    if(usuario->publicaciones.size()==0){
      cout << "no tienes publicaciones hechas" <<endl;}
    usuario->mostrarPublicaciones();
    fresquito();
    break;
    case 3:
    usuario->crearPublicacion(rs);
    break;
    case 4:
    cout << "introduzca el ID del perfil de su amigo" <<endl;
    cin>> var;
    login(var);
    break;
    case 5:{
    rs.mostrarUsuarios();
    cout << "introduzca el ID del amigo a agregar" << endl;
    amikos:
    cin>>var;
    Usuario* amigo = rs.getUsuario(var);
    if(amigo!=nullptr) {
      if(amigo->getid()!=usuario->getid()){
      usuario->agregarAmigo(amigo);
      cout << "se agrego con exito" << endl;}
      else {cout << "este usuario es usted mismo, introduzca un id diferente" <<endl;
      goto amikos;
      }
    }
    else {
      cout<<"introduzca un ID correcto" << endl;
      goto amikos;
    }
   } break;
    case 6:
    return;
    break;
    case 7:
    rs.sugerencias(usuario);
    fresquito();
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

void fresquito(){
  cout << "presione espacio para continuar" << endl;
  char k;
    do {
        k = getkey();
    } while (k != ' ');}

