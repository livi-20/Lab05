#include <stdio.h>
#include "dynarray.h"

int main(void){
    DynArray *arr = crear_dyn(2);
    if (arr == NULL) {
        fprintf(stderr, "Error: no se pudo crear el arreglo dinámico.\n");
        return 1;
    }


    if (push(arr, 10) != 0) {
        fprintf(stderr, "Error al hacer push.\n");
    }
    if (push(arr, 20) != 0) {
        fprintf(stderr, "Error al hacer push.\n");
    }
    if (push(arr, 30) != 0) {
        fprintf(stderr, "Error al hacer push.\n");
    }

    printf("Después de hacer push de 10, 20, 30:\n");
    print(arr);

    if (remove_at(arr, 1) != 0) {
        fprintf(stderr, "Error en remove_at.\n");
    }

    printf("Después de remove_at(1):\n");
    print(arr);

    int valor = 0;
    if (get(arr, 0, &valor) == 0){
        printf("Elemento en índice 0: %d\n", valor);
    } else {
        printf("No se pudo obtener el elemento en índice 0.\n");
    }

    destroy(arr);

    return 0;
}