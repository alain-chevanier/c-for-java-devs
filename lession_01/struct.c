#include<stdio.h>
#include<stdlib.h>

/*
Equivalente en java
class Node {
  int x;
  Node next;
  Node prev;
}
*/
struct node {
  int value;
  struct node* next; // Tiene que ser un pointer
  struct node* prev; // Tiene que ser un pointer
};

// Recibe la direccion de un nodo
void set_node_value(struct node* pointer_to_node, int new_value) {
  // (*pointer_to_node).value = new_value;
	pointer_to_node->value = new_value;
	// Es azucar sintactito de "(*pointer_to_node).value = new_value;"
}

void set_node_value_wrong_way(struct node node, int new_value) {
  node.value = new_value;
}

struct node* create_node(int value) {
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
  // malloc regresa un void*, por eso hacemos un down casting

  set_node_value(new_node, value);
  return new_node;
}

int main() {
	// Struct node, por omisión vive en el registro de activacion (stack)
	// de esta funcion
	struct node head; // Node head = new Node();???
  head.value = 5;

  printf("1) head value: %d\n", head.value);

  set_node_value(&head, 3);
  //set_node_value_wrong_way(head, 3);

  printf("2) head value: %d\n", head.value);

  // Inicializamos el nodo siguiente.
  struct node next_node;
  next_node.value = 7;

  // Asignamos el siguiiente de hear
  // head.next = next_node; // esto es invalido
  head.next = &next_node;

  printf("next_node value: %d\n", head.next->value);
  // es equivalente a printf("next_node value: %d\n", next_node.value);

  struct node* pointer_to_head = &head;
  printf("pointer_to_head next_node value: %d\n", pointer_to_head->next->value);


  // Esta es la cantidad de memoria que utiliza un struct node en
  // la computadora donde ejecutamos este programa.
  printf("sizeof(struct node) -> %lu\n", sizeof(struct node));

  // Asi creamos un "struct node" en el heap
  struct node* other_node = create_node(8);

  printf("other_node value: %d\n", other_node->value);

  // C no tiene garbage collector, por lo que la memoria que pedimos del Heap
  // la tenemos que liberar explicitamente llamando la función free
  free(other_node);
	
	return EXIT_SUCCESS; // 0
}