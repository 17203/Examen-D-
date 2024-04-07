#include "Usuario.h"
#include <iostream>
using namespace std;
int Usuario::numId = 0;

Usuario::Usuario(string nom){
  this->id=numId++;
  this->nombre= nom;
  this->edad= 21;
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
    for (int i=0; i<amigos.size(); i++){
      cout << amigos[i]->nombre <<endl;
    }
}
void Usuario::mostrarPublicaciones(){
  for (int i=0; i<publicaciones.size(); i++){
      cout << "publicacion numero #"<< i+1 <<endl;
      cout << publicaciones[i]->fecha <<endl;
      cout << publicaciones[i]->contenido <<endl;
      cout << endl;
    }
}


void Usuario::agregarAmigo(Usuario* nuevoAmigo){
  amigos.push_back(nuevoAmigo);
  nuevoAmigo->amigos.push_back(this);
}
void Usuario::crearPublicacion(RedSocial& rs) {
   Publicacion* np = new Publicacion(this, "", "");
   cout << "introduzca la fecha" <<endl;
   cin >> np->fecha;
   cout << "introduzca el contenido" << endl;
   cin >> np->contenido;
   publicaciones.push_back(np);
   rs.agregarPublicacion(np);
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