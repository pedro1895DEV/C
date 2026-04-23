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
// }list_t;

// size_t list_size(list_t *l) {
//     return l->size;
// }

// bool list_empty (list_t *l) {
//     return l->size == 0;
// }

// void list_initialize (list_t **l) {
//     (*l) = malloc(sizeof(list_t));
//     (*l)->head = NULL;
//     (*l)->tail = NULL;
//     (*l)->size = 0;
// }

static list_node_t *list_new_node ( int data) {
    list_node_t *new_node = malloc(sizeof(list_node_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void list_append (list_t *l, int data) {
    list_node_t *new_node = list_new_node(data);
    if (list_empty(l)) {
        l->head = new_node;
    } else {
        l->tail->next = new_node;
    }
    l->tail = new_node;
    l->size++;
}

void list_insertionsort_insert(list_t* l,int data) {
    list_node_t *new_node = list_new_node(data);
    if (list_empty(l)) {
        l->head = new_node;
    } else if (list_size(l) == 1) {
        if (data < l->head->data) {
            new_node->next = l->head;
            l->head = new_node;
        } else {
            l->head->next = new_node;
            l->tail = new_node;
        }
    }
    else {
        list_node_t *aux = l->head;
        list_node_t *chosen = l->head->next;
        while (chosen != NULL) {
            if (chosen->data < data) {
                aux = aux->next;
                chosen = chosen->next;
            }
            else if (data < aux->data) {
                new_node->next = l->head;
                l->head = new_node;
                break;
            }
            else {
                if (chosen->data < data) {
                    list_append(l, data);
                    break;
                }
                else {
                    aux->next = new_node;
                    new_node->next = chosen;
                    break;
                }
            }
        }
        if (chosen == NULL) {
            l->tail->next = new_node;
            l->tail = new_node;
        }
    }
    l->size++;
}

// int main () {
//     list_t *lista;
//     list_initialize(&lista);


    // list_append(lista, 1);
    // list_append(lista, 2);
    // list_append(lista, 4);
    // list_append(lista, 5);
    // list_insertionsort_insert(lista, 0);
    // list_insertionsort_insert(lista, 6);
    // list_insertionsort_insert(lista, 0);
    // list_insertionsort_insert(lista, 1);
    // list_insertionsort_insert(lista, 0);
    // list_insertionsort_insert(lista, 9);
    // list_insertionsort_insert(lista, 2);
    // list_insertionsort_insert(lista, 5);


//     list_node_t *aux = lista->head;
//     while (aux != NULL) {
//         printf("%d-> ", aux->data);
//         aux = aux->next;
//     } printf("\n");
//     return 0;
// }