// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
#include "grader.h"

// typedef struct list_node_t {
//     int data;
//     struct list_node_t *next;
// }list_node_t;

// typedef struct list_t {
//     list_node_t *head;
//     list_node_t *tail;
//     size_t size;
// }list_t;

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

// size_t list_size (list_t *l) {
//     return l->size;
// }

// bool list_empty(list_t *l) {
//     return list_size(l) == 0;
// }

// void list_append (list_t *l, int data) {
//     list_node_t *new_node = list_new_node(data);
//     if (list_empty(l)) {
//         l->head = new_node;
//     } else {
//         l->tail->next = new_node;
//     }
//     l->tail = new_node;
//     l->size++;
// }

void list_reverse (list_t *l) {
    list_node_t *curr = l->head;
    list_node_t *next = NULL;
    list_node_t *prev = NULL;
    l->tail = l->head;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    l->head = prev;
}

// int main () {
//     list_t *lista;
//     list_initialize(&lista);
//     list_append(lista, 1);
//     list_append(lista, 2);
//     list_append(lista, 4);
//     list_append(lista, 5);
//     list_reverse(lista);

//     list_node_t *aux = lista->head;
//     while (aux != NULL) {
//         printf("%d-> ", aux->data);
//         aux = aux->next;
//     }printf("NULL\n");
//     return 0;
// }