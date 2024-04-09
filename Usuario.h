#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>
#include "Publicacion.h"
#include "RedSocial.h" 
using namespace std;
class RedSocial;
class Usuario {
private:
    static int numId;
    int id;

public:
    string nombre;
    int edad;
    string nacionalidad;
    vector<Usuario*> amigos;
    vector<Publicacion*> publicaciones;
    vector<Usuario*> sugerencia;

    Usuario(string nom);
    Usuario(string nomb, int ed);
    Usuario(string nombr, int ed, string nac);

    int getid();
    void mostrar();
    void mostrarAmigos();
    void mostrarPublicaciones();
    void agregarAmigo(Usuario* nuevoAmigo);
    void crearPublicacion(RedSocial& rs);
    Usuario* getAmigo(int id);
};

#endif // USUARIO_H