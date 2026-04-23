#include <stdio.h>
#include <stdlib.h>
//#include "grader.h"
#include <stdbool.h>

typedef struct list_node_t {
    int data;
    struct list_node_t *next;
}list_node_t;

typedef struct list_t {
    list_node_t *head;
    list_node_t *tail;
    size_t size;
}list_t;

void list_initialize (list_t **l) {
    (*l) = malloc(sizeof(list_t));
    (*l)->head = NULL;
    (*l)->tail= NULL;
    (*l)->size= 0;
}

size_t list_size (list_t *l) {
    return l->size;
} 

bool list_empty(list_t *l) {
    return list_size(l) == 0 ? 1 : 0;
}

static list_node_t *list_new_node (int data) {
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
        l->tail = new_node;
    }
    l->tail = new_node;
    l->size++;
}

void list_concat(list_t *l1, list_t *l2) {
    list_node_t *aux = l1->head;
    list_node_t *aux2 = l2->head;
    while(aux2!=NULL) {
        list_append(l1, aux2->data);
        aux2 = aux2->next;
    }
}

int main () {
    // list_t *l1 = NULL;
    // list_t *l2 = NULL;
    // list_initialize(&l1);
    // list_initialize(&l2);

    // list_append(l1, 1);
    // list_append(l1, 2);
    // list_append(l1, 4);

    // list_append(l2, 3);
    // list_append(l2, 5);
    // list_append(l2, 6);

    // list_concat(l1, l2);

    // list_node_t *aux = l1->head;
    // while (aux!= NULL) {
    //     printf("%d -> ", aux->data);
    //     aux = aux->next;
    // }

    // printf("\n");

    return 0;
}