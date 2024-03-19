class Usuario{
int id;
public:
string nombre;
int edad;
string nacionalidad;
vector<Usuario*> amigos;
vector <publicacion*> publicaciones;

int getid();
void mostrar();
void mostrarAmigos();
void mostrarPublicaciones();
void agregarAmigo(Usuario* nuevoAmigo);
