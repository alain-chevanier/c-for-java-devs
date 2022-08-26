#include<stdio.h>

int main() {
	// este es un entero en el registro de activacion
    int value = 3;
    // este es un apuntador a la direccion en la que se encuentra value
    int* pointer_to_value = &value; // Integer
    // & indireccion

    // *pointer_to_value es una derreferenciacion del apuntador pointer_to_value,
    // es decir esta extrayendo el valor de la direccion a la que apunta pointer_to_value
    printf("address: %p value: %d\n", pointer_to_value, *pointer_to_value); // *pointer_to_value == value

    *pointer_to_value = 5;

    printf ("value: %d\n", value);
  
    return 0;
}