#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definimos una variable global que es visible en este archivo y en otros.
static int some_var = 7;

static void increment_some_var () {
	some_var++;
}

static
int get_some_var () 
{
	return some_var;
}

int main() {
	int some_var = 5;
	printf("GLOBAL -> some_var : %d\n", some_var);
	some_var += 8;
	printf("GLOBAL -> some_var : %d\n", some_var);

	printf("GLOBAL -> some_var : %d\n", get_some_var ());
	increment_some_var ();
	printf("GLOBAL -> some_var : %d\n", get_some_var ());
	return 0;
}