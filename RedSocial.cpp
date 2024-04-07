#include "RedSocial.h"
#include "Usuario.h"
#include "Publicacion.h"
#include <iostream>
using namespace std;


void RedSocial::sugerencias(Usuario* usuario){
cout << "segun su edad, le recomendamos a los siguientes usuarios como amigos " << endl;
if(usuario->edad>=60){
      for(int i=0; i<usuariosM60.size(); i++){
        cout << (*(next(usuariosM60.begin(), i)))->nombre << endl;}
}else if(usuario->edad>=40){
  for(int i=0; i<usuariosM40.size(); i++){
    cout << (*(next(usuariosM40.begin(), i))) << endl;}
}else if(usuario->edad>=20){
  for(int i=0; i<usuariosM20.size(); i++){
    cout << (*(next(usuariosM20.begin(), i)))->nombre << endl;}
}else if(usuario->edad>=14){
  for(int i=0; i<usuariosM14.size(); i++){
    cout << (*(next(usuariosM14.begin(), i)))->nombre << endl;}
}
} 



RedSocial::RedSocial(string nombre){
this->nombre= nombre;
}
RedSocial::RedSocial(string nombre,  vector<Usuario*> usuarios):RedSocial(nombre){
this->usuarios = usuarios;
} 
RedSocial::RedSocial(string nombre, vector<Usuario*> usuarios, vector<Publicacion*> publicaciones):RedSocial(nombre, usuarios){
this->publicaciones = publicaciones;
} 
void RedSocial::categoriaUsuario(){
for(int i=0;i<numeroDeUsuarios; i++){
if(usuarios[i]->edad>=60){
  usuariosM60.insert(usuarios[i]);
}else if(usuarios[i]->edad>=40){
  usuariosM40.insert(usuarios[i]);
}else if(usuarios[i]->edad>=20){
  usuariosM20.insert(usuarios[i]);
}else if(usuarios[i]->edad>=14){
  usuariosM14.insert(usuarios[i]);
}
}
}
void RedSocial::agregarUsuario(Usuario* nuevo){
  numeroDeUsuarios++;
  usuarios.push_back(nuevo);
  categoriaUsuario();
}
void RedSocial::mostrarUsuarios(){
  system("cls");
  cout << "existen: " <<numeroDeUsuarios <<" usuarios en la red social actualmente, los cuales son:" << endl;
  for (int i=0; i<usuarios.size(); i++){
      cout << usuarios[i]->nombre <<"  ID:"<< usuarios[i]->getid() << endl;
    }
}
void RedSocial::mostrarPublicaciones(){
  cout << "existen: " <<numeroDePublicaciones <<" publicaciones en la red social actualmente"<<endl;
for (int i=0; i<publicaciones.size(); i++){
      cout << publicaciones[i]->usuario->nombre <<endl;
      cout << publicaciones[i]->fecha <<endl;
      cout << publicaciones[i]->contenido <<endl;
    }
}

void RedSocial::agregarPublicacion(Publicacion* nuevaPublicacion){
  numeroDePublicaciones++;
  publicaciones.push_back(nuevaPublicacion);
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