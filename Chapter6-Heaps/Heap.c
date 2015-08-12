#include <stdio.h>
#include <stdlib.h>

#include "Heap.h"

#define LEFT(x) (2*x) + 1
#define RIGHT(x) (2*x) + 2
#define PARENT(x) x/2

/*
 * -----------------------------------------------------------
 *  Heap_Init --
 *      Initialize the main priority queue structure.
 * -----------------------------------------------------------
 */
Heap_t
Heap_Init(int (*cmp)(const void *a, const void *b),
          size_t capacity)
{
    Heap_t *newHeap;
    newHeap = malloc(sizeof(Heap_t));
    NP_CHECK(newHeap);
    newHeap->cmp = cmp;
    newHeap->capacity = capacity;
    newHeap->data = malloc(sizeof(*(newHeap->data)) * capacity);
    NP_CHECK(newHeap->data);
    newHeap->size = 0;
    return newHeap;
}

/*
 * -------------------------------------------------------------
 *  Heap_DeInit --
 *      Deinitialize the heap.
 * -------------------------------------------------------------
 */
void
Heap_Deinit(Heap_t *newHeap)
{
    if (newHeap == NULL) {
        return;
    }

    free(newHeap->data);
    free(newHeap);
}

/*
 * ------------------------------------------------------------
 *  Heap_Insert --
 *      Insert an element into the heap.
 * ------------------------------------------------------------
 */
void
Heap_Insert(Heap_t *newHeap, const void *data)
{
    NP_CHECK(newHeap);
    int curPos = newHeap->size;
    if (newHeap->size == newHeap->capacity) {
        printf("Heap is full.");
        return;
    }

    newHeap->data[newHeap->size++] = data;
    
    while(curPos > 0 && 
            newHeap->cmp(newHeap->data[curPos],
                         newHeap->data[PARENT[curPos]]) > 0) {
        void *tmp = newHeap->data[PARENT[curPos]];
        newHeap->data[PARENT[curPos]] = newHeap->data[curPos];
        newHeap->data[curPos] = tmp;
        curPos = PARENT[curPos];
    }
}

/*
 * ------------------------------------------------------------
 *  Heap_Delete(Heap_t *newHeap)
 *      Delete an element from heap.
 * ------------------------------------------------------------
 */
void *
Heap_Delete(Heap_t *newHeap)
{
    NP_CHECK(newHeap);
    if (newHeap->size < 1) {
        printf("Heap is empty.");
        return NULL;
    }

    data = newHeap->data[size - 1];
    newHeap->size--;
    Heap_Heapify(newHeap);
    return data;
}




