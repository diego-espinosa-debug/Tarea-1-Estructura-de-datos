#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cola.h"
#include "list.h"

// se define el numero maximo de caracteres permitido
#define MAXIMO 50

typedef struct {
  char titulo[51];
  char autor[51];
  char genero[51];
  unsigned int isbn;
  char ubicacion[51];
  char estado[51];
  Cola *reservas;
} LibroInf;

bool verificarLong(const char *ingresado) {
  return (strlen(ingresado) <= MAXIMO);
}

void ingreso_de_datos_tipoChar(char *caracteres) {
  char auxiliar[MAXIMO + 1];
  do {

    if(fgets(auxiliar, MAXIMO + 1, stdin) == NULL){
      printf("Error al leer la entrada. Intente nuevamente.\n");
      continue;  
    }
    auxiliar[strlen(caracteres) - 1] = '\0';

    if (!verificarLong(auxiliar)) {
      printf(
          "Se excede el limite de caracteres permitido intente nuevamente\n");
    } else {
      strcpy(caracteres, auxiliar);
    }

  }while(!verificarLong(caracteres));

  return;
}

void importarLibros(List *libros) {
  char nomArchivo[51];
  printf("ingrese el nombre del archivo CSV\n");
  ingreso_de_datos_tipoChar(nomArchivo);

  FILE *archivo = fopen(nomArchivo, "r");
  if (archivo == NULL) {
    printf("No se logro abrir el archivo\n");
    return;
  }

  char linea[310];
  while (fgets(linea, sizeof(linea), archivo) != NULL) {

    LibroInf *nuevo = (LibroInf *)malloc(sizeof(LibroInf));
    nuevo->reservas = CreateQueue();

    char *fragmento = strtok(linea, ",");
    if (fragmento != NULL) {
      strcpy(nuevo->titulo, fragmento);
      listpushback(libros, nuevo);
    }
  }
  fclose(archivo);
}
void exportarLibros(List *libros) {

  char nomArchivo[51];
  printf("Ingrese el nombre del archivo CVS para exportar los libros");
  ingreso_de_datos_tipoChar(nomArchivo);

  FILE *archivo = fopen(nomArchivo, "w");
  if (archivo == NULL) {
    printf("No se pudo crear el archivo");
    return;
  }

  LibroInf *actual = firstList(libros);

  while (actual != NULL) {
    fprintf(archivo, "%s,%s,%s,%u,%s,%s\n", actual->titulo, actual->autor,
            actual->genero, actual->isbn, actual->ubicacion, actual->estado);

    exportarReservas(archivo, actual->reservas);
    actual = nextList(libros);
  }
  fclose(archivo);
  printf("Libros exportados con exito\n");
}

int main(void) {

  List *libros = createList();
  int intruccion = 0;

  do {

    printf("Si desea registrar un libro, escriba 1\n");
    printf("Si desea ver los datos de un libro ingrese 2\n");
    printf("Si desea ver todos los libros inscritos escriba 3\n");
    printf("Si desea reservar un libro, escriba 4\n");
    printf("Si desea cancelar la reserva de un libro, escriba 5\n");
    printf("Si desea retirar un libro, escriba 6\n");
    printf("Si desea devolver un libro, escriba 7\n");
    printf("Si desea ver los libros prestados escriba 8\n");
    printf("Si desea importar libros desde un archivo CSV, escriba 9\n");
    printf("Si desea exportar libros a un archivo CSV, escriba 10\n");
    printf("Si desea terminar el programa ingrese 0");
    intruccion = scanf("%d", &intruccion);

    switch (intruccion) {
    case 1: // registrar libros 

      printf("\n");
      LibroInf *nuevo = (LibroInf *)malloc(sizeof(LibroInf));
      nuevo->reservas = CreateQueue();

      printf("Ingrese el titulo\n");
      ingreso_de_datos_tipoChar(nuevo->titulo); // para el titulo
      printf("Ingrese el autor\n");
      ingreso_de_datos_tipoChar(nuevo->autor); // para el autor
      printf("Ingrese el género\n");
      ingreso_de_datos_tipoChar(nuevo->genero); // para el genero
      printf("Ingrese el ISBN\n");
      nuevo->isbn = scanf("%u", &(nuevo->isbn)); // para el isbn
      printf("Ingrese la ubicación\n");
      ingreso_de_datos_tipoChar(nuevo->ubicacion); // para la ubicacion

      listpushback(libros, nuevo);

      break;
    case 2: // mostrar datos del libro

      printf("Para buscar debera ingresar el titulo y el autor\n");

      char tituloBus[51];
      char autorBus[51];

      printf("ingrese el titulo\n");
      ingreso_de_datos_tipoChar(tituloBus);

      printf("ingrese el autor\n");
      ingreso_de_datos_tipoChar(autorBus);

      // scanf("%50[^,]%50[^,]\n", tituloBus, autorBus); // borrar seguramente

      LibroInf *buscado = firstList(libros);

      if (buscado == NULL) {
        printf("Actualmente no hay libros registrados\n");
        return 0; // no estoy seguro si esto es buena ida (el return 0)
      }

      while (buscado != NULL) {
        if (strcmp(buscado->titulo, tituloBus) == 0 &&
            strcmp(buscado->autor, autorBus) == 0) {
          printf("EL titulo del libro es %s\n", buscado->titulo);
          printf("EL autor del libro es %s\n", buscado->autor);
          printf("El genero del libro es %s\n", buscado->genero);
          printf("El ISBN del libro es %u\n", buscado->isbn);
          printf("El libro se encuentra en %s\n", buscado->ubicacion);
          printf("El estado del libro es %s\n", buscado->estado);
          // falta mostrar reservas
          break; // de nuevo, no estoy seguro
        }

        buscado = nextList(libros);
      }

      if (buscado == NULL) {
        printf("El libro que se quiso buscar no se encuentra en la base de "
               "datos\n");
      }

      break;
    case 3: // mostrar todos los libros
      printf("\n");
      LibroInf *mostrar = firstList(libros);

      while (mostrar != NULL) {
        printf("EL titulo del libro es %s\n", mostrar->titulo);
        printf("EL autor del libro es %s\n\n", mostrar->autor);

        mostrar = nextList(libros);
      }

      break;
    case 4: // reservar libro
      printf("Para reservar el libro tendra que escribir el titulo, autor y el "
             "nombre del estudiante\n");
      char tituloBus4[51]; // le agregamos el 4 para que no haya un error de
                           // redefinition
      char autorBus4[51];  // le agregamos el 4 para que no haya un error de
                           // redefinition
      char reservando[51];
      printf("ingrese el titulo\n");
      ingreso_de_datos_tipoChar(tituloBus4);
      printf("ingrese el autor\n");
      ingreso_de_datos_tipoChar(autorBus4);
      printf("ingrese el nombre del estudiante que desee reservar el libro\n");
      ingreso_de_datos_tipoChar(reservando);

      LibroInf *buscado4 = firstList(libros);

      while (buscado4 != NULL) {
        if (strcmp(buscado4->titulo, tituloBus4) == 0 &&
            strcmp(buscado4->autor, autorBus4) == 0) {
          colapushfront(buscado4->reservas, reservando);
          strcpy(buscado4->estado, "reservado");
          break;
        }
        buscado4 = nextList(libros);
      }

      if (buscado4 == NULL) {
        printf("no se encontró el libro que se desea reservar\n");
      }

      break;
    case 5: // cancelar reserva de libro
      printf("Si desea cancelar la reserva de un libro debera escribir el "
             "titulo, autor y el nombre del estudiante\n");
      char tituloBus5[51];  // le agregamos el 5 para que no haya un error de
                            // redefinition
      char autorBus5[51];   // le agregamos el 5 para que no haya un error de
                            // redefinition
      char reservando5[51]; // le agregamos el 5 para que no haya un error de
                            // redefinition

      printf("ingrese el titulo\n");
      ingreso_de_datos_tipoChar(tituloBus5);
      printf("ingrese el autor\n");
      ingreso_de_datos_tipoChar(autorBus5);
      printf("ingrese el nombre del estudiante que desee cancelar la reserva "
             "del libro\n");
      ingreso_de_datos_tipoChar(reservando5);

      // hay que hacer las funciones para quitar la recerva con la cola

      LibroInf *buscado5 = firstList(libros);

      while (buscado5 != NULL) {
        if (strcmp(buscado5->titulo, tituloBus5) == 0 &&
            strcmp(buscado5->autor, autorBus5) == 0) {
          popcurrentcola(buscado5->reservas, reservando5);
          break;
        }
        buscado5 = nextList(libros);
      }

      if (buscado5 == NULL) {
        printf("no se encontró el libro que se desea cancelar la reserva\n");
      }

      break;

    case 6: // retirar libro

      printf("Para retirar un libro habra que escribir el titulo, autor y el "
             "nombre del estudiante que desee retirar el libro\n");

      char tituloBus6[51];  // le agregamos el 6 para que no haya un error de
                            // redefinition
      char autorBus6[51];   // le agregamos el 6 para que no haya un error de
                            // redefinition
      char reservando6[51]; // le agregamos el 6 para que no haya un error de
                            // redefinition
      printf("ingrese el titulo\n");
      ingreso_de_datos_tipoChar(tituloBus6);
      printf("ingrese el autor\n");
      ingreso_de_datos_tipoChar(autorBus6);
      printf("ingrese el nombre del estudiante que desee retirar el libro\n");
      ingreso_de_datos_tipoChar(reservando6);

      // hay que hacer las funciones para esto : Si el libro está "Disponible" o
      // si el estudiante es el primero en la cola de reservas para un libro
      // "Reservado", entonces el libro puede ser retirado y su estado cambia a
      // "Prestado". Si el libro ya está "Prestado" o el estudiante no tiene
      // prioridad, se muestra un aviso. Un libro prestado lo tiene el primer
      // estudiante de la cola de reservas.
      LibroInf *buscado6 = firstList(libros);

      while (buscado6 != NULL) {
        if (strcmp(buscado6->titulo, tituloBus6) == 0 &&
            strcmp(buscado6->autor, autorBus6) == 0 &&
            (strcmp(buscado6->estado, "disponible") == 0 ||
             strcmp(buscado6->estado, "reservado") == 0)) {
          int *opcionRetirar = retirarcola(buscado6->reservas, reservando6);

          if (*opcionRetirar == 0) {
            printf("puede retirar el libro sin problema");
            strcpy(buscado6->estado, "prestado");
          } else {
            printf("lo sentimos, no puede retirar el libro ya que no tienes "
                   "prioridad");
            break;
          }

          break;
        } else if (strcmp(buscado6->titulo, tituloBus6) == 0 &&
                   strcmp(buscado6->autor, autorBus6) == 0 &&
                   strcmp(buscado->estado, "prestado") == 0) {
          printf("lo sentimos, el libro que deseas retirar ya fue prestado");
          break;
        }
        buscado6 = nextList(libros);
      }

      if (buscado6 == NULL) {
        printf("no se encontró el libro que se desea retirar\n");
      }

      break;
    case 7: // devolver libro
      printf("Para devolver el libro se debera escribir el titulo y autor del "
             "libro devuelto\n");
      char tituloBus7[51]; // le agregamos el 7 para que no haya un error de
                           // redefinition
      char autorBus7[51];  // le agregamos el 7 para que no haya un error de
                           // redefinition
      char reservando7[51];

      printf("ingrese el titulo\n");
      ingreso_de_datos_tipoChar(tituloBus7);
      printf("ingrese el autor\n");
      ingreso_de_datos_tipoChar(autorBus7);
      printf("ingrese el nombre del estudiante que desee retirar el libro\n");
      ingreso_de_datos_tipoChar(reservando7);

      LibroInf *buscado7 = firstList(libros);

      while (buscado7 != NULL) {
        if (strcmp(buscado7->titulo, tituloBus7) == 0 &&
            strcmp(buscado7->autor, autorBus7) == 0) {
          int *numEsatado = devueltaLibro(buscado7->reservas, reservando7);

          if (*numEsatado == 0) {
            strcpy(buscado7->estado, "disponible");
          } else {
            strcpy(buscado7->estado, "reservado");
          }

          break;
        }
        buscado7 = nextList(libros);
      }

      if (buscado7 == NULL) {
        printf("no se encontró el libro que se desea cancelar la reserva\n");
      }

      break;
    case 8: // mostrar libros prestados
      //!!!Todo el while es copiado de un mostrar todos los libros como idea,
      //!hay que codificarlo!!!!
      printf(" \n");
      LibroInf *buscado8 = firstList(libros);

      while (buscado8 != NULL) {

        if (strcmp(buscado8->estado, "prestado") == 0) {
          char *prestado = poseeLibro(buscado8->reservas);

          printf("EL titulo del libro es %s\n", buscado8->titulo);
          printf("EL autor del libro es %s\n", buscado8->autor);
          printf("Se le presto al estudiante %s",
                 prestado); // hay que hacer el codigo para saber a quien se le
                            // presto
        }

        buscado8 = nextList(libros);
      }

      break;
    case 9: // Importar libros desde un archivo CSV
      // insertar el codigo para recibir los archivos CSV
      importarLibros(libros);

      printf("libros importados con exito\n");
      break;
    case 10: // Exportar libros a un archivo CSV
      exportarLibros(libros);

      break;

    case 0:
      printf("Gracias por utilizar este programa...");
      break;
    default:
      printf("Opcion invalida, ingrese un valor valido");
    }

  } while (intruccion != 0);
  cleanList(libros);
  return 0;
}
