#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct list_node_t{
    char *data;
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

size_t list_size(list_t *l) {
    return l->size;
}

bool list_empty(list_t *l) {
    return list_size(l) == 0 ? true : false;
}

static void list_delete_node (list_node_t *node) {
    free(node);
}

static list_node_t *list_new_node(char* data) {
    list_node_t *new_node = malloc(sizeof(list_node_t));
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

void list_append(list_t *l, char* data) {
    list_node_t *new_node = list_new_node(data);
    if (list_empty(l)) {
        l->head = new_node;
    }
    else {
        l->tail->next = new_node;
    }

    l->tail = new_node;
    l->size++;
}

char* list_access_head(list_t *l) {
    assert(!(list_empty(l)));
    return (l->head->data);
}

void list_remove_head (list_t *l) {
    assert(!list_empty(l));
    list_node_t *node = l->head;
    l->head = l->head->next;
    if (list_size(l) == 1) {
        l->tail = NULL;
    }

    list_delete_node(node);
    l->size--;
}


void list_remove_tail(list_t *l) {
    assert(!list_empty(l));
    list_node_t *node = l->tail;
    if (list_size(l) == 1) {
        l->head = NULL;
    } else {
        l->tail->next = NULL;
    }

    list_delete_node(node);
    l->size--;
}

void list_remove (list_t *l, size_t i) {
    assert(!list_empty(l) && i < list_size(l));
    list_node_t *node;
    if (list_size(l) == 1 || i == 0) {
        list_remove_head(l);
    } else if (i ==  list_size(l) - 1){
        list_remove_tail(l);
    } else {
        list_node_t *aux = l->head;
        size_t k;
        for (k = 0; k < i; k++) {
            aux = aux->next;
        }
        node = aux;
        list_delete_node(node);
        l->size--;
    }
}

int main () {
    int n, x;
    scanf("%d %d", &n, &x);
    list_t *lista;
    list_initialize(&lista);


    for (int i = 0; i < n; i++) {
        char* participante = malloc(sizeof(char) * 31);
        scanf("%30s", participante);
        list_append(lista, participante);
    }

    int valor = (x - 1) % list_size(lista);
    while (list_size(lista) > 1) {
        int target = valor % lista->size;
        list_remove(lista, target);
        valor = target + x - 1;
    }

    printf("%s", list_access_head(lista));

    return 0;
}