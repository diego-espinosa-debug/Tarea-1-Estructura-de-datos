Esta aplicación permite al usuario gestionar los libros de una libreria. Puede agregar libros y su informacion, como los son el titulo, el autor, su genero, su ISBN y su ubacion. Ademas se permite crear reservas para cada libro en specifico, para ello, necesita del nombre y autor del libro y luego el nombre de la persona que quiere reservar el libro.

clonar el repositorio;
git clone <https://github.com/diego-espinosa-debug/Tarea-1-Estructura-de-datos>

gestor de tareas:
cd <path al lugar donde se desea clonar>

compilar el codigo:
gcc main.c cola.c list.c -o tarea1

ejecutar aplicacion:
./tarea1


funcionalidades;
-agrega libros a la lista del libro correctamente
-permite ver los datos del libro deseado efectivamente, pero no deja ver el titulo
-agrega gente para reservar de manera efectiva
-cancela la reserva de manera efectiva
-permite retirar libros
-permite devolver libros
-importa efectivamente
-exporta efectivamente
-termina el programa de manera efectiva


Errores conocidos: 
1. se necesita un doble enter para el autor y género, se cree que estos errores son debidos a caracteres residuales que quedan luego de los fgets
2. al intentar retirar un libro que se encuentra en la base de datos el programa se cierra de manera subita, se cree que es debido a un error en cuanto a la manipulacion del libro buscado3
3. Este github corresponde al 8vo, ya que los intentos anteriores no pudimos guardarlo de manera correcta debido a diferentes situacions, como que no compila en replit pero en visual si, que compile en replit pero en visual no, que compile en un replit pero en otro replit no, que no se conecte con github, que no se ejecute como debe, gran parte del tiempo usado fue en estos problemas y por eso no pudimos hacer gran variedad de cosas en este replit (cosas como mas pruebas o que nos quedasemos cortos de tiempo, ya que madrguamos varios dias y empezamos el trabajo el marte de la semana pasada). Es debido a esto que la cantidad de commits es alarmantemente baja

a mejorar:
-Hacer la tarea con mas tiempo
-mejorar el nombre de variables, ya que repetimos mucho la varibale buscar
-Hacer mas pruebas para el codigo
-preguntar mas frecuentemente en referencia al uso de replit y/o visual studio

Contribuciones:

Javier Caamaño
Diseño interfaz del usuario
Coomprobacion de lectura
Creacion de diferentes funciones en main, cola y list
Auto-evacluación: 3 (Aporte excelente)
Evaluacion compañero; Muy buen trabajo, gran parte de lo hecho fue en conjunto y el codigo fue hecho gran parte en conjunto, por lo que es complicado dicernir quien hizo que parte.

Diego Espinsoa
Creacion de diferentes funciones en main, cola y list
Investigacion y resolucion con problemas relacionados con el uso de programa(replit y/o visual)
Creacion de structs usados
Auto-evacluación: 3 (Aporte excelente)
Evaluacion compañero: Excelente disposicion a la hora de trabajar aportando muchas cosas en cada momento, animando en los momentos de fustración, no se puede especificar mucho quien hizo cada cosa, debido a que en todo momento estuvimos los dos agregando o modificando ya sea las funciones o el main en si.
