
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "list.h"


// NULL < - BEG < - > END -> NULL
// size = 0
void list_init (struct list* list) {
  // Introducimos estos asserts para evitar fal
  assert(list != NULL);

  list->size = 0;
  (list->beg).next = &(list->end);
  (list->beg).prev = NULL;
  (list->end).prev = &(list->beg);
  (list->end).next = NULL;
}

bool list_is_empty(struct list* list) {
  assert(list != NULL);
  // TODO: Finish implementation 
  return list->size == 0;
  // return (list->beg).next == &(list->end);
}

// NULL < - BEG <-> N_1 <-> .... <-> N_k < - > END -> NULL
// NULL < - BEG <-> NEW_NODE (value) <-> N_1 <-> .... <-> N_k < - > END -> NULL
int list_push_front(struct list* list, int value) {
  assert(list != NULL);

  //struct list_node new_node;
  
  struct list_node* new_node = (struct list_node*) malloc(sizeof(struct list_node));
  assert(new_node != NULL);
  
  new_node->value = value;
  new_node->next = (list->beg).next; // NEW_NODE -> next = N1
  new_node->prev = &(list->beg); // NEW_NODE -> prev = BEG
  new_node->next->prev = new_node; // N1 -> prev = NEW_NODE
  (list->beg).next = new_node; // BEG -> next = NEW_NODE
  
  list->size++;
  return list->size;
}

// NULL < - BEG <-> N_1 <-> .... <-> N_k < - > END -> NULL
// NULL < - BEG <-> N_1 <-> .... <-> N_k <-> NEW_NODE  < - > END -> NULL
int list_push_back(struct list* list, int value) {
  assert(list != NULL);
  
  struct list_node* new_node = (struct list_node*) malloc(sizeof(struct list_node));
  assert(new_node != NULL);
  
  new_node->value = value;
  new_node->next = &(list->end);
  new_node->prev = (list->end).prev;
  new_node->prev->next = new_node;
  (list->end).prev = new_node;
  
  list->size++;
  return list->size;
}


struct list* list_copy (struct list* list) {
  assert(list != NULL);
  // TODO: Finish implementation 
  return NULL;
}

int list_max (struct list* list) {
  assert(list != NULL);
  int max = 0;
  // TODO: Finish implementation 
  return max;
}

// NULL < - BEG <-> N_1 <-> .... <-> N_k < - > END -> NULL
void list_print (struct list* list) {
  assert(list != NULL);
  
  struct list_node* it = (list->beg).next;
  struct list_node* end = &(list->end);
  while(it != end) {
    printf("%d -> ", it->value);
    it = it->next;
  }
  printf("NULL\n");
}

void list_free (struct list* list) {
  assert(list != NULL);

  struct list_node* it = (list->beg).next;
  struct list_node* end = &(list->end);
  while(it != end) {
    struct list_node* cur_node = it;
    it = it->next;
    free (cur_node);
  }
}
