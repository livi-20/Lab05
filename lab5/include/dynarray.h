#ifndef DYNARRAY_H
#define DYNARRAY_H
#include <stddef.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacidad;
} DynArray;

DynArray *crear_dyn(size_t inicial);

void destroy(DynArray *arr);

int push(DynArray *arr, int valor);

int remove_at(DynArray *arr, size_t index);

void print(const DynArray *arr);

#endif