#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Esta version de main recibe argumentos, en C los identificadores de arreglo son
// simplemente apuntadores, por lo que para saber el tamaño del arreglo es
// necesario pasar una variable que indique cuantos elementos contiene dicho
// arreglo.
int main(int argc, char** args) { 
  // en java String[] args -> El equivalente en C char*[] args -> (char*)* args
  int i = 0;
  // Imprime los argumentos con los cuales es ejecutado este programa
  for(; i < argc; i++) {
    printf("%s\n", args[i]);
  }

  return 0;
}
