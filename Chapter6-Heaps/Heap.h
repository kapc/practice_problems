#ifndef _HEAP_H
#define _HEAP_H

#include <stdio.h>

/**
 * Debugging macro.
 *
 * Checks for a NULL pointer and prints the error messages, source file via stderr.
 *
 * If the check failsthe program exits with error -1.
 */
#define NP_CHECK(_ptr) \
{ \
    if (NULL == (_ptr)) { \
        fprintf(stderr, "%s:%d NULL POINTER :%s \n", \
                __FILE__, __LINE__, #ptr); \
        exit(-1); \
    } \
} \

/*
 * Api list.
 */
typedef struct Heap {
    size_t size;                                // Actual Size of the heap
    size_t totalHeapCapacity;                   // total heap capacity.
    void **data;                                // An array of void pointer actual heap.
    int (*cmp) (const void* a, const void *b);  // A pointer to comparator function.
} Heap_t

Heap_t * HeapInit(int (*cmp)(const void * a, const void *b),
                  size_t capacity);
void HeapDeinit(Heap_t *);
void HeapInsert(Heap_t *, const void *data);
void* HeapDelete(Heap_t *);

#endif

