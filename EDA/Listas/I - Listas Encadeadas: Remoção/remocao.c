// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
#include <assert.h>
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

// static list_node_t *list_new_node(int data) {
//     list_node_t *new_node = malloc(sizeof(list_node_t));
//     new_node->data = data;
//     new_node->next = NULL;
// }

// size_t list_size (list_t *l) {
//     return l->size;
// }

// bool list_empty (list_t *l) {
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

void list_remove (list_t *l, size_t i) {
    assert(!list_empty(l));
    if (list_size(l) == 1) {
        l->head = NULL;
        l->tail = NULL;
    }
    else if (i == 0) {
        l->head = l->head->next;
    } else if (i == l->size - 1) {
        list_node_t *aux = l->head;
        list_node_t *aux2 = l->head->next;
        while (aux2 != NULL) {
            if (aux2 == l->tail) {
                l->tail = aux;
                l->tail->next = NULL;
                break;
            }
            aux = aux->next;
            aux2 = aux2->next;
        }
    } else {
        list_node_t *aux = l->head;
        list_node_t *aux2 = l->head->next;
        int count = 0;
        while (count < l->size - 1) {
            if (count == i - 1) {
                aux->next = aux2->next;
                aux2 = NULL;
                break;
            }
            count++;
            aux = aux->next;
            aux2 = aux2->next;
        }
    }
    l->size--;
}

// int main () {
//     list_t *lista;
//     list_initialize(&lista);
//     list_append(lista, 1);
//     list_append(lista, 2);
//     list_append(lista, 4);
//     list_append(lista, 5);
//     list_remove(lista, 0);

//     list_node_t *aux = lista->head;
//     while (aux != NULL) {
//         printf("%d-> ", aux->data);
//         aux = aux->next;
//     }printf("NULL\n");

//     return 0;
// }