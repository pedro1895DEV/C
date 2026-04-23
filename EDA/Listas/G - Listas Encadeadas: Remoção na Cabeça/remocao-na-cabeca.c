// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
#include "grader.h"
#include <assert.h>

// typedef struct list_node_t {
//     int data;
//     struct list_node_t *next;
// }list_node_t;

// typedef struct list_t {
//     list_node_t *head;
//     list_node_t *tail;
//     size_t size;
// }list_t;

// size_t list_size (list_t *l) {
//     return l->size;
// }

// bool list_empty (list_t *l) {
//     return list_size(l) == 0;
// }

// void list_initialize (list_t **l) {
//     (*l) = malloc(sizeof(list_t));
//     (*l)->head = NULL;
//     (*l)->tail = NULL;
//     (*l)->size = 0;
// }

// static list_node_t *list_new_node (int data) {
//     list_node_t *new_node = malloc(sizeof(list_node_t));
//     new_node->data = data;
//     new_node->next = NULL;
// }

// void list_append(list_t *l, int data) {
//     list_node_t *new_node = list_new_node(data);
//     if (list_empty(l)) {
//         l->head = new_node;
//     } else {
//         l->tail->next = new_node;
//     }
//     l->tail = new_node;
//     l->size++;
// }

void list_remove_head (list_t *l) {
    assert(!list_empty(l));
    l->head = l->head->next;
    l->size--;
}

// int main () {
//     list_t *lista;
//     list_initialize(&lista);

//     list_append(lista, 5);
//     list_append(lista, 9);
//     list_append(lista, 3);
//     list_append(lista, 1);
//     list_append(lista, 12);
//     list_remove_head(lista);

//     list_node_t *aux = lista->head;
//     while (aux != NULL) {
//         printf("%d-> ", aux->data);
//         aux = aux->next;
//     } printf("NULL\n");
//     return 0;
// }