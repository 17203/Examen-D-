#ifndef REDSOCIAL_H
#define REDSOCIAL_H

#include <string>
#include <vector>
#include <set>
#include "Usuario.h"
#include "Publicacion.h"
using namespace std;
class RedSocial {
private:
    vector<Usuario*> usuarios;
    vector<Publicacion*> publicaciones;
    string nombre;
    int numeroDeUsuarios;
    int numeroDePublicaciones;
    set<Usuario*> usuariosM60;
    set<Usuario*> usuariosM40;
    set<Usuario*> usuariosM20;
    set<Usuario*> usuariosM14;

public:
    RedSocial(
string nombre);
    RedSocial(
string nombre, vector<Usuario*> usuarios);
    RedSocial(
string nombre, vector<Usuario*> usuarios, vector<Publicacion*> publicaciones);

    void agregarUsuario(Usuario* nuevo);
    void mostrarUsuarios();
    void mostrarPublicaciones();
    void agregarPublicacion(Publicacion* nuevaPublicacion);
    void sugerencias(Usuario* usuario);
    void categoriaUsuario();
    Usuario* getUsuario(int id);
};

#endif // REDSOCIAL_H