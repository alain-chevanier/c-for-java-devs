#include <stdio.h>
#include <stdlib.h>

int* create_array () {
  // int my_array[3] = {1, 2, 3};
  int* my_array = (int*) malloc(3 * sizeof(int));
  my_array[0] = 1;
  return my_array;
}

/*
 STACK:
 -> main (-> create_array) (-> malloc)
 -> printf (my_array)
 */
int main(int argc, char *argv[]) {
  // int my_array[3];// = {1, 2, 3};
  // my_array[0] = 1;
  int* my_array = create_array ();

  // printf("Arreglo creado\n");


  int* other_array = (int *) malloc (3 * sizeof(int));
  other_array[0] = 5;

  printf("my array [0] -> %d\n", my_array[0]);

  printf("other array [0] -> %d\n", other_array[0]);

  return 0;
}
