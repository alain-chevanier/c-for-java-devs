#include <stdbool.h>

#ifndef LISTA_LIGADA_H
#define LISTA_LIGADA_H

// Definicion de los nodos internos de los lista
struct list_node {
  int value;
  struct list_node* prev;
  struct list_node* next;
};

// Definicion de una lista doblemente ligada
struct list {
  // Ojo estos no son apuntadores
  struct list_node beg;
  struct list_node end;
  int size;
};

typedef struct list linked_list;

/*
 * Inicializa una lista
 */
void list_init (struct list*);
//void list_init (linked_list*);

/*
 * Decide si una lista es vacia.
 */
bool list_is_empty (struct list*);
  
/*
 * Esta función crea una copia de la lista que recibe
 * como argumento.
 */
struct list* list_copy (struct list*);

/*
 * Inserta un nodo que contiene el valor value al principio de
 * de la lista.
 */
int list_push_front (struct list*, int);

/*
 * Inserta un nodo que contiene el valor value al final 
 * de la lista. Regre
 */
int list_push_back (struct list*, int);

/*
 * Calcula el valor máximo contenido en algún nodo de la 
 * lista. 
 */
int list_max (struct list*);

/*
 * Esta función imprime los valores enteros contenidos
 * en una lista. 
 */
void list_print (struct list*);

/*
 * Libera la memoria ocupada por los nodos internos de
 * la lista.
 */
void list_free (struct list*);

char* list_to_string (struct list*);

#endif
