#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct list_node_t{
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
    (*l)->tail = NULL;
    (*l)->size = 0;
}

static list_node_t *list_new_node(int data) {
    list_node_t *new_node = malloc(sizeof(list_node_t));

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

size_t list_size(list_t *l) {
    return l->size;
}

bool list_empty(list_t *l) {
    return list_size(l) == 0 ? 1 : 0;
}

void list_prepend(list_t *l, int data) {
    list_node_t *new_node = list_new_node(data);
    new_node->next = l->head;
    l->head = new_node;
    if (list_empty(l)) {
        l->tail = new_node;
    }

    l->size++;
}

int main () {
    list_t* lista = NULL;
    list_initialize(&lista);
    //list_prepend(lista, 55);

    printf("%zu\n", list_size(lista));
    printf("Lista está vazia? %d\n", list_empty(lista));
    return 0;
}