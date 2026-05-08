#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct processos {
    char name[30];
    int pid;
    int time;
    int final_time;
}processos;

typedef struct queue_t {
    size_t front;
    size_t back;
    size_t size;
    size_t capacity;
    processos *queue;
}queue_t;

void queue_initialize (queue_t **q) {
    (*q) = malloc(sizeof(queue_t));
    (*q)->back = 3;
    (*q)->front = 0 ;
    (*q)->capacity = 4;
    (*q)->size = 0;
    (*q)->queue = malloc(sizeof(processos) * (*q)->capacity);
}

size_t queue_size (queue_t *q) {
    return q->size;
}

bool queue_empty (queue_t *q) {
    return queue_size(q) == 0;
}

void queue_push (queue_t *q, processos data) {
    if (q->size == q->capacity) {
        q->capacity *= 2;
        q->queue = realloc(q->queue, q->capacity * sizeof(processos));
    }
    q->back++;
    if (q->back == q->capacity) {
        q->back = 0;
    }
    q->queue[q->back] = data;
    q->size++;
}

void queue_pop (queue_t *q) {
    q->front++;
    q->size--;
    if (q->front == q->capacity) {
        q->front = 0;
    }
}

processos queue_front (queue_t *q) {
    return q->queue[q->front];
}

void calcula_tempo (queue_t *q, int quantum, processos p) {
    int tempo = 0;
    while (!queue_empty(q)) {
        if (queue_front(q).time > quantum) {
            processos sobra = queue_front(q);
            sobra.time -= quantum;
            tempo+=quantum;
            queue_pop(q); 
            queue_push(q, sobra);
            
        } 
        else {
            tempo+=queue_front(q).time;
            processos final = queue_front(q);
            p.final_time = tempo;
            printf("%s %d %d ms\n", final.name, final.pid, tempo);
            queue_pop(q);
        }
    }
}

int main () {
    int n, q;
    scanf("%d %d", &n, &q);
    queue_t *fila;
    queue_initialize(&fila);
    processos p;
    
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", p.name, &p.pid, &p.time);
        queue_push(fila, p);
    }

    calcula_tempo(fila, q, p);
    return 0;
}