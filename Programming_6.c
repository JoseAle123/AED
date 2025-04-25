#include <stdio.h>

struct Clase {
    int numeroDeEstudiantes;
    float calificaciones[100];
};

void ingresarNotas(struct Clase *a) {
    printf("Ingrese el número de estudiantes:\n");
    scanf("%d", &a->numeroDeEstudiantes);

    printf("Ingrese las notas de los estudiantes:\n");
    for(int i = 0; i < a->numeroDeEstudiantes; i++) {
        scanf("%f", &a->calificaciones[i]);
    }
}

void mostrarNotas(struct Clase *a){
    for (int i = 0; i < a->numeroDeEstudiantes; i++)
    {
        printf("nota: %f \n", a->calificaciones[i]);
    }
}

int mayorNota(struct Clase *a){
    int max = 0;
    for (int i = 0; i < a->numeroDeEstudiantes; i++)
    {
        if(max < a->calificaciones[i]){
            max = a->calificaciones[i];
        }
    }
    return max;
}

int main(){
    struct Clase a;

    //INGRESAR Y MOSTRAR NOTAS
    ingresarNotas(&a);
    mostrarNotas(&a);

    //MAYOR NOTA
    int max = mayorNota(&a);
    printf("mayor nota: %f\n", max);
}