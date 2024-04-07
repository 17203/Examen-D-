# Examen-D-

El archivo README.md del repositorio de GitHub debe contar con lo siguiente:
a. Nombre del proyecto. (Cómo se llama tu red social)
b. Integrantes del proyecto.
c. Explicación de la estructura del proyecto. (Descripción general de cada archivo)
d. Explicación de qué diferencia a tu red social de las demás.

Proyecto / Examen Parcial 2
Red Social medio funcional :D
RedSocial:
main.cpp:
Contiene 4 fuciones
main- Menu principal, contiene las 5 opciones requeridas en la rubrica, utiliza un switch para seleccionar
menuDeUsuario-enseña el menu de usuario y ademas una opcion extra la cual son las recomendaciones, en caso de entrar al perfil de un amigo, en lugar de regresar directamente al menu de la red social(si se usa la opción), se regresa al usuario que acceso al perfil de amigo
login-Función simple para entrar en perfiles de usuario
fresquito- El nombre fue en crisis por lo que solo significa que mantiene el codigo viendose fresco, función simple que espera que el usurio presione espacio para continuar
--------------------
RedSocial.h y .cpp:
Declaraciones y funciones de RedSocial
Se incluyeron vectores para categorizar usuarios por sus grupos de edad, 14-19/20-39/40-59/60+
Se crearon las funciones para categorizar usuarios y para sugerir amistades
--------------------
Usuario.h y .cpp:
Declaraciones y funciones de RedSocial
Se incluyo RedSocial& rs en crear publicacion para agregar rs ya que este provocaba un error de declaración
--------------------
Publicacion.h y .cpp:
Declaraciones y funciones de Publicación
Ningun cambio mayor :D
---------------------
Diferenciador: 
Recomendación de usuarios amigos por grupos de edades
No permite crear cuentas de usuarios menores de 13 años
No permite agregarse a si mismo como amigo D:
---------------------------------
Aprendizajes:
utilizar set y su sintaxis, la cual consiste en un apuntador, un operador next para acceder al siguiente elemtno a partir de .begin() y un operador i
