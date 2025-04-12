#include <stdio.h>

int compararLongitud(int longitud1, int longitud2){
    if(longitud1 == longitud2){
        return 1;
    }
    return 0;
}

void mostrarLista(int lista[], int longitud){
    for(int i = 0; i < longitud; i++){
        printf("numero: %d\n", lista[i]);
    }
}

void hadamardProduct(int lista1[], int lista2[], int longitud){
    int lista3[longitud];
    for(int i = 0; i < longitud; i++){
        lista3[i] = lista1[i] * lista2[i];
    }
    mostrarLista(lista3, longitud);
}

int dotProduct(int lista1[], int lista2[], int longitud) {
    int count = 0;
    for (int i = 0; i < longitud; i++) {
        count += lista1[i] * lista2[i];
    }

    return count;
}

int main(){
    int lista1[] = {1, 3, 4, 5};
    int lista2[] = {7, 3, 5, 12, 20};
    int longitud1 = sizeof(lista1) / sizeof(lista1[0]);
    int longitud2 = sizeof(lista2) / sizeof(lista2[0]);

    int comparacion = compararLongitud(longitud1, longitud2);
    if(comparacion == 0){
        printf("Ambas listas deben ser del mismo tamanio. \n");
    }
    else{
        printf("Hadamard product: \n");
        hadamardProduct(lista1, lista2, longitud1);
        int dotProduct1 = dotProduct(lista1, lista2, longitud1);
        printf("Dot product: %d \n", dotProduct1);
    }
}