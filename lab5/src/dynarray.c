#include <stdio.h>
#include <stdlib.h>
#include "dynarray.h"

DynArray *crear_dyn(size_t inicial) {
    DynArray *arr = malloc(sizeof(DynArray));
    if (arr == NULL) {
        return NULL;
    }


    if (inicial == 0) {
        inicial = 1;
    }

    arr->data = malloc(inicial *sizeof(int));
    if (arr->data == NULL) {
        free(arr);
        return NULL;
    }

    arr->size = 0;
    arr->capacidad = inicial;

    return arr;
}

void destroy(DynArray *arr) {
    if (arr == NULL) {
        return;
    }

    free(arr->data);
    arr->data = NULL;
    free(arr);
}

int push(DynArray *arr, int valor) {
    if (arr == NULL) {
        return -1;
    }

    if (arr->size == arr->capacidad){
        size_t new_capacidad = arr->capacidad *2;
        int *new_data = realloc(arr->data, new_capacidad * sizeof(int));
        if (new_data == NULL) {
            return -1;
        }

        arr->data = new_data;
        arr->capacidad = new_capacidad;
    }

    arr->data[arr->size] = valor;
    arr->size++;
    return 0;
}

int remove_at(DynArray *arr, size_t index){
    if (arr == NULL) {
        return -1;
    }
    if (index >= arr->size) {
        return -1;
    }
    for (size_t i = index; i + 1 < arr->size; i++) {
        arr->data[i] = arr->data[i + 1];
    }

    arr->size--;
    return 0;
}

int get(const DynArray *arr, size_t index, int *out){
    if (arr == NULL) {
        return -1;
    }

    if (index >= arr->size){
        return -1;
    }

    for (size_t i = index; i + 1 < arr->size; i++) {
        arr->data[i] = arr->data[i+1];
    }

    if (index >= arr->size) {
        return -1;
    }

    *out = arr->data[index];
    return 0;
}

void print(const DynArray *arr) {
    if (arr == NULL) {
        printf("[]\n");
        return;
    }

    printf("[");
    for (size_t i = 0; i < arr->size; i++){
        printf("%d", arr->data[i]);
        if (i + 1 < arr->size) {
            printf(", ");
        }
    }
    printf("]\n");
}