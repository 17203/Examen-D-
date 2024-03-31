pragma once publicacion
#include "base.h"
class Publicacion: public base {
public:
string contenido;

void mostrarPublicacion(){
cout << fecha << endl;
cout << contenido<< endl;
/*agregar a usuario que creo la publicacion*/

}
Publicacion(Usuario* usu, string fech, string cont){
    id = usu;
    a = fech;
    contenido = cont;

}
};


/*
Publicacion:
Propiedades privadas: id (int) Propiedades públicas:
fecha (string)
Contenido (string)
Usuario* usuario.
Métodos públicos:
void mostrarPublicacion
Muestra la fecha en la que se creó la publicación, su contenido y el nombre del usuario que creó la publicación. Constructores:
Publicacion (Usuario* usuario, string fecha, string contenido)
Crea una publicación con la fecha, contenido y usuario asignado.
*/