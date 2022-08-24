#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definimos la firma de una funcion para que podamos utilizarla aunque
// aun no este implementada
size_t str_len(char*);

// Esta funcion decide si una cadena es un palindromo
bool
is_palindrom(char* str) 
{
  int beg = 0, end = str_len(str) - 1;

  while(beg < end) {
    if(str[beg++] != str[end--]) {
      return false;
    }
  }
  
  return true;
}

// Regreasa la longitud de la cadena recibida
size_t 
str_len(char* str) 
{
  int i = 0;
  size_t len = 0;
  // la cadena termina cuando encontramos el caracter especial '\0', cuyo valor ascii es 0
  while(str[i++] != '\0') { // str[i++]
    len++;
  }
  return len;
}

// Esta version de main recibe argumentos, en C los identificadores de arreglo son
// simplemente apuntadores, por lo que para saber el tamaño del arreglo es
// necesario pasar una variable que indique cuantos elementos contiene dicho
// arreglo.
int main(int argc, char** args) { // String[] args -> char*[] args -> (char*)* args
  // Las cadenas se representan como arreglos de caracteres, con un caracter especial al final.
  char my_string[] = "asdffdsa";// {'a', 's', ... , 'd', 's', 'a', '\0'} los strings terminan con \0

  printf("%zu\n", str_len(my_string));

  // Un valor es verdadero siempre que sea distinto de cero
  bool value = is_palindrom (my_string);
  if (value) {
    printf("True\n");
  } else {
    printf("False\n");
  }

  printf("%s\n", my_string);
  

  char str[] = {'h', 'e', 'l', 'l', 'o', '\0'};// "hello";
  char* pt_str = str;
  // sizeof es un operador, que regresa el numero de bytes que ocupa el tipo de dato
  // del tipo o identificador pasado como argumento
  printf("sizeof(char) %lu\n", sizeof(char));
  printf("sizeof(char*) %lu\n", sizeof(char*));
  printf("sizeof(str) %lu\n", sizeof(str));
  printf("sizeof(pt_str) %lu\n", sizeof(pt_str));

  return 0;
}
