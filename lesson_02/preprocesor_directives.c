/*
 * El preprocesador es un programa que procesa nuestro codigo antes
 * de que sea compilado. 
 *
 * Todas las directivas del preprocesador comienzan con el simbolo #
 */


/*
 * #include indica al preprocesador que debe de copiar y pegar el archivo
 * de cabeceras objetivo.
 *
 * Si el nombre del archivo es indicado por medio de <...>, entonces este
 * es buscado en las cabeceras del sistema operativo.
 *
 * Si el nombre del archivo es indicado por medio de "...", entonces este
 * es buscado en las cabeceras de nuestro proyecto. 
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
//#include "list.h"


/*
 * Este tipo de definiciones usualmente las llamamos macros.
 */
// Podemos definir constantes
#define LIMIT 5
// Podemos definir funciones, muchas veces es necesario incluir
// todos los posibles parentesis de otra manera podemos tener errores
// inesperados, dado que no podemos garantizar que la presedencia de
// operadores se respete al hacer sustitucion textual
#define ADD(x, y) ((x) + (y))

// Observa que al remover estos paréntesis, 
// la sustitución no se realiza de forma correcta
#define MULT(x, y) (x * (y))

/*
 * Recordemos que los simbolos del preprocesador se sustituyen antes de que
 * el codigo sea compilado, es decir el compilador no se enterea que 
 * LIMIT, ADD y MULT existen, pues solo ve las expresiones correspondientes
 * sustituidas por el preprocesador.
 */
int main() {
  printf("LIMIT %d\n", LIMIT);
  printf("ADD(%d, %d) -> %d\n", 1, 2, ADD(1, 2));
  printf("MULT(%d, %d) -> %d\n", 4+1, 8, MULT(4+1, 8));
  printf("MULT(%d, %d) -> %d\n", ADD(4, 1), 8, MULT(ADD(4, 1), 8));

  return 0;
}
