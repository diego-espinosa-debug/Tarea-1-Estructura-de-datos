#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
  void * data;
  Node * next;
  Node * prev;
};

struct List {
  Node * head;
  Node * tail;
  Node * current;
};

typedef List List;

Node * createNode(void * data) {
  Node * new = (Node *)malloc(sizeof(Node));
  assert(new != NULL);
  new->data = data;
  new->prev = NULL;
  new->next = NULL;
  return new;
}

List * createList() {
  List* libro = (List*) malloc(sizeof(List));
  libro->head = NULL;
  libro->tail = NULL;
  libro->current = NULL;
  return libro;
}

void * firstList(List * libro) {
  if (!libro->head)return NULL;
  libro->current = libro->head;
  return(libro->head->data);
}

void * lastList(List * libro) {
  if (!libro->tail)return NULL;
  libro->current = libro->tail;
  return(libro->current->data);
}

void * nextList(List * libro) {
  if(!libro->current)return NULL;
  if(!libro->current->next)return NULL;
  libro->current = libro->current->next;
  return(libro->current->data);
}

void * prevList(List * libro) {
  if(!libro->current)return NULL;
  if(!libro->current->prev)return NULL;
  libro->current = libro->current->prev;
  return(libro->current->data);
}

void * listpushback(List * libro, void * data) {
  Node* nuevo = createNode(data);

  libro->current = libro->tail;
  
  if(libro->head == NULL)
  {
    libro->head = nuevo;
    libro->tail = nuevo;
  }else {
    libro->current->next = nuevo;
    nuevo->prev = libro->current;
    libro->tail = nuevo;
  }

  return NULL;
}

void cleanList(List * libro){
  while(libro->head != NULL){
    Node * current = libro->head;
    libro->head = libro->head->next;
    free(current->data);
    free(current);
  } 
  libro->tail = NULL;
  libro->current = NULL;
}

