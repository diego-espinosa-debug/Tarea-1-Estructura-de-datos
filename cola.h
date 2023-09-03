#ifndef Cola_h
#define Cola_h
#include <stdio.h>
#include <stdbool.h>
typedef struct Cola Cola;

Cola * CreateQueue(void);

void * colapushfront(Cola * Cola, void * data);

void * popcurrentcola(Cola * Cola, void * data);

int * retirarcola(Cola * Cola, void * data);

int * devueltaLibro(Cola * Cola, void * data);

void exportarReservas(FILE* archivo, Cola* reservas);

char * poseeLibro(Cola * Cola);

bool estaVacia(Cola * cola);



#endif /* Cola_h */
