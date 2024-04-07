#ifndef PUBLICACION_H
#define PUBLICACION_H

#include <string>
using namespace std;
class Usuario;

class Publicacion {
private:
    int id;

public:
    string fecha;
    string contenido;
    Usuario* usuario;

    Publicacion(Usuario* usu, string fech, string cont);
    void mostrarPublicacion();
};

#endif // PUBLICACION_H