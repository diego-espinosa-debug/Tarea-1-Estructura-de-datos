#ifndef List_h
#define List_h

typedef struct List List;

List * createList(void);

void * firstList(List * list);

void * lastList(List * list);

void * nextList(List * list);

void * prevList(List * list);

void * listpushback(List * list, void * data);

void mostrarLista( List* libro);

void cleanList(List * list);

#endif /* List_h */
