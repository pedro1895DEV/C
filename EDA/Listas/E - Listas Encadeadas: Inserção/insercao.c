// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
#include "grader.h"

// typedef struct list_node_t {
//     int data;
//     struct list_node_t *next;
// } list_node_t;

// typedef struct list_t {
//     list_node_t *head;
//     list_node_t *tail;
//     size_t size;
// } list_t;

// void list_initialize (list_t **l) {
//     (*l) = malloc(sizeof(list_t));
//     (*l)->head = NULL;
//     (*l)->tail = NULL;
//     (*l)->size = 0;
// }

// size_t list_size (list_t *l) {
//     return l->size;
// }

// bool list_empty (list_t *l) {
//     return list_size(l) == 0;
// }

static list_node_t *list_new_node (int data) {
    list_node_t *new_node = malloc(sizeof(list_node_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void list_insert (list_t *l, int data, size_t i) {
    list_node_t *new_node = list_new_node(data);
    if (list_empty(l)) {
        l->head = new_node;
        l->tail = new_node;
    } else if (i == 0) {
        new_node->next = l->head;
        l->head = new_node;
    } else if (i >= l->size) {
        l->tail->next = new_node;
        l->tail = new_node;
    } else {
        list_node_t *aux = l->head;
        size_t j;
        for (j = 0; j < i - 1; j++) {
            aux = aux->next;
        }
        new_node->next = aux->next;
        aux->next = new_node;
    }
    l->size++;
}
 
// int main () {
//     list_t *lista;
//     list_initialize(&lista);

//     list_insert(lista, 1, 0);
//     list_insert(lista, 2, 1);
//     list_insert(lista, 4, 2);
//     list_insert(lista, 5, 3);
//     list_insert(lista, 3, 2);

//     list_node_t *aux = lista->head;
//     while (aux != NULL) {
//         printf("%d-> ", aux->data);
//         aux = aux->next;
//     }

//     return 0;
// }