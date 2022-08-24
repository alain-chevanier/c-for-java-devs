#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char** args) {
  if (true) {
    printf("True is a constant defined in stdbool.h\n");
  }

  if (!false) {
    printf("True is a constant defined in stdbool.h, false is 0\n");
  }

  // 0 (NULL) es false, y cualquier otro valor entero es true
  if (NULL) {
    printf("True\n");
  } else {
    printf("False\n");
  }

  return 0;
}
