#include "Publicacion.h"
#include "Usuario.h"
#include <iostream>
using namespace std;

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
