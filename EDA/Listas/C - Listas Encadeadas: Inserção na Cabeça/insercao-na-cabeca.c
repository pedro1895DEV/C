// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
#include "grader.h"

// typedef struct list_node_t{
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

// size_t list_size (list_t *l) {
//     return l->size;
// }

// bool list_empty (list_t *l) {
//     if (list_size(l) == 0) {
//         return 0;
//     } else {
//         return true;
//     }
// }

static list_node_t *list_new_node (int data) {
    list_node_t *new_node = malloc(sizeof(list_node_t));
    
    new_node->data = data;
    new_node->next = NULL;
}

void list_prepend(list_t *l, int data) {
    list_node_t *new_node = list_new_node(data);
    new_node->next = l->head;
    l->head = new_node;
    if (list_empty(l)) {
        l->head = new_node;
    }
    l->size++;
}


// int main () {
    // list_t *l = NULL;
    // list_initialize(&l);
    // list_prepend(l, 5);
    // list_prepend(l, 4);
    // list_prepend(l, 2);
    // list_prepend(l, 1);
    // list_prepend(l, 3);

    // list_node_t *aux = l->head;
    // while (aux != NULL) {
    //     printf("%d -> ", aux->data);
    //     aux = aux->next;
    // }

    // return 0;
// }