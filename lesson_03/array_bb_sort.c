#include <stdio.h>
#include <stdlib.h>

/*
 * Para el caso de constantes en el paso de preprocesamiento se sustituyen
 * todas las ocurrencias de la constante con el valor especificado. Por lo
 * anterior las constantes no tienen tipo, pues la verificación de tipos es
 * hecha en tiempo de complilación.
 */
#define CONSTANTE 5 // public static final int CONSTANTE = 5;
#define ARRAY_SIZE 6 // public static final int ARRAY_SIZE = 5;

/*
 * Esta función regresa TRUE si a < b y regresa FALSE en caso
 * contrario.
 */
int cmp_less (int a, int b) 
{
  return a < b;
}

/*
 * Esta función regresa TRUE si a > b y regresa FALSE en caso
 * contrario.
 */
int cmp_great (int a, int b) {
  return a > b;
} 

/*
 * Implementación del algoritmo bubble sort. Toma como argumento un apuntador
 * a la primera posición del arreglo de enterosa ordenar, la longitud del arreglo
 * y un apuntador a una función de comparación, cuyo trabajo es decidir si el
 * primer argumento que recibe es mayor que el segundo.
 */
void 
bb_sort (int* array, size_t length, int (* cmp_greater) (int, int)) 
{
  int i = 0, j = 0, tmp;

  while (i < length) {
    j = 0;

    while (j < length - 1 - i) {
      if (cmp_greater(array[j], array[j+1])) {
	      tmp = array[j];
        array[j] = array[j+1];
        array[j+1] = tmp;
      }
      j++;
    }
    i++;
  }
}

static 
void print_array (int *array, size_t length) 
{
  int i = 0;
  printf ("[");
  for (; i < length; i++) {
    printf ("%d, ", array[i]);
  }
  printf ("]\n");
}

int main() 
{
  int array[] = {9,CONSTANTE, 4,1, 6, -1};
  // int[] array = new int[] {9,CONSTANTE, 4,1, 6, -1};

  printf ("Arreglo Original: ");
  print_array (array, ARRAY_SIZE);

  // Utilizando la función de comparación natural >, provoca que
  // bubble sort ordene ascendentemente.
  bb_sort (array, ARRAY_SIZE, cmp_great);
  printf ("Tras ordenar utilizando el criterio de comparacion '>': ");
  print_array (array, ARRAY_SIZE);
  
  // Utilizando la función de comparación natural <, provoca que
  // bubble sort ordene descendentemente sin modificar en lo absoluto}
  // el algoritmo.
  bb_sort (array, ARRAY_SIZE, cmp_less);
  printf ("Tras ordenar utilizando el criterio de comparacion '<': ");
  print_array (array, ARRAY_SIZE);

  return 0;
}
