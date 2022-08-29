
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

/*
 * Función main para ejecutar las pruebas de la 
 * implementación de listas.
 */
int main() {
  
  // struct list list;
  linked_list list;
  list_init(&list);
  list_push_back(&list, 3);
  list_push_back(&list, 5);
  list_push_front(&list, 0);
  
  list_print(&list);

  list_free(&list);

  /*
  struct list* copy = list_copy(&list);
  list_print(copy);

  printf ("El valor máximo en la lista es: %d\n", list_max(copy));

  list_free(copy);
  */
  

  return 0;
}
