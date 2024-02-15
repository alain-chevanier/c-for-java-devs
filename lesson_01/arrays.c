#include<stdio.h>
#include<stdlib.h>

int* create_array () {
	int* values = (int*) malloc(sizeof(int) * 3); // esto se crea en el HEAP
	// int[] values = new int[3]; // La memoria para este arreglo se crea en el HEAP (monticulo)
	values[0] = 25;
	values[1] = 5;
	values[2] = 1;
	return values;
}

int main() {
	// Arrays
	int values[3]; // esto se crea en el stack
	// No hay un equivalente directo en Java. int[] values = new int[3]; 
	// Java por medio de new siempre asigna memoria en el heap
	values[0] = 7;
	values[1] = 5;
	values[2] = 1;

	// Values es en realidad es un apuntador a la primera psicion el arreglo
	int* pointer_to_values = values;
	void* void_pointer_to_values = values;

	printf("array: %p\n", values); 
	printf("pointer to array: %p\n", pointer_to_values);
	printf("void pointer to array: %p\n", void_pointer_to_values);

	// imprime cuantos bytes ocupa un entero en el sistema actual
	printf("size of interger %d\n", sizeof(int));
	// Regresa el numero de bytes que ocupa el arreglo completo
	printf("size of array: %d\n", sizeof(values));
	// Regresa el numero de bytes que ocupa una direccion de memoria 
	// en la computadora donde se ejecuta
	printf("size of array through pointer: %d\n", sizeof(pointer_to_values) );

	// Aritmetica de apuntadores, *(values + 2) == values[2]
	printf("pointer: %p, pointer + 2: %p\n", values, values + 2);
	printf("value at position 2 %d\n", *(values + 2));
	printf("value at position 2 %d\n", values[2]);

	// Este arreglo lo creamos en el heap por medio de create_array
	int* array_head = create_array();
	printf("other array: %p\n", array_head);
	printf("other array value at 0: %d\n", *array_head);

	// C no tiene garbage collector, por lo que la memoria que pedimos del Heap
  // la tenemos que liberar explicitamente llamando la función free
  // Vamos a utilizar  malloc muy poco durante el curso
  free (array_head);

	return EXIT_SUCCESS; // 0 definido en stdlib
}
