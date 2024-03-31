#ifndef RS
#define RS
class RedSocial{
    private:
    vector <Usuario> usuarios;
    vector <Publicacion> publicaciones;

    public:
    string nombre;
    int numeroDeUsuarios;
    int numeroDePublicaciones;
    
    RedSocial(); 
    RedSocial(string nom, int nu, int np);
    
    void agregarUsuario();
    void mostrarUsuario();
    void mostrarPublicacion();
    Usuario* getUsuario (int id);
}

#endif

/*Métodos públicos:
int getid
Regresa el id del Usuario.
void mostrar
Muestra los datos del usuario, incluyendo el ID del usuario.
void mostrarAmigos
Muestra una lista de todos los amigos del usuario.
void mostrarPublicaciones
■Muestra todas las publicaciones que ha hecho el usuario.
void agregarAmigo (Usuario* nuevoAmigo)
Agrega un usuario existente de la Red Social como amigo.
■ Al agregar un Usuario como amigo, ambos Usuarios se vuelven amigos, es decir Usuario A está en la lista de amigos de Usuario B y Usuario B está en la lista de amigos del Usuario A
void crearPublicacion
Crea una nueva publicación para el usuario.
■ Crea la publicación directamente desde el método y agrega el apuntador de la publicación al listado de publicaciones del usuario.
Usuario* getAmigo(int id)*/