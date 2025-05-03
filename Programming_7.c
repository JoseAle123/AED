#include <stdio.h>
#include <stdlib.h>

//QUESTION 1
void printVector(int v[], int n){
    for(int i = 0; i < n; i++){
        printf("number: %d\n", v[i]);
    }
}

int* filterPositives(int* v, int n, int* size){
    for(int i = 0; i < n; i++){
        if(v[i] >= 0){
            *size = *size + 1;
        }
    }

    int *positiveNumbers = malloc(sizeof(int) * (*size));
    *size = 0;
    for (int i = 0; i < n; i++)
    {
        if(v[i] >= 0){
            positiveNumbers[*size] = v[i];
            *size = *size + 1;
        }
    }
    return positiveNumbers;
}

//QUESTION 2

double*** create3DMatrix(int m, int n, int k){
    double ***matrix = (double ***)malloc(sizeof(double **) * m);
    for(int i = 0; i < m; i++){
        matrix[i] = (double **)malloc(sizeof(double *) * n);
        for(int j = 0; j < n; j++){
            matrix[i][j] = (double *)malloc(sizeof(double) * k);
        }
    }
    return matrix;
}

void enterValues(double ***matrix, int m, int n, int k){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            for(int l = 0; l < k; l++){
                matrix[i][j][l] = (double)(i + j + l);
            }
        }
    }
}

void print3DMatrix(double ***matrix, int m, int n, int k){
    for(int i = 0; i < m; i++){
        printf("Capa %d:\n", i);
        for(int j = 0; j < n; j++){
            for(int l = 0; l < k; l++){
                printf("%.2f ", matrix[i][j][l]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void free3DMatrix(double ***matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            free(matrix[i][j]);  
        }
        free(matrix[i]); 
    }
    free(matrix);
}



int main(){
    //QUESTION 1
    int vector[7] = {1, 3, -5, -17, 8, -35, 84};
    printf("vector original: \n");
    printVector(vector, 7);

    int size = 0;
    int *newVector = filterPositives(vector, 7, &size);
    printf("vector positive: \n");
    printVector(newVector, size);


    //QUESTION 2
    int m = 2, n = 3, k = 4;
    double*** matriz = create3DMatrix(m, n, k);
    enterValues(matriz, m, n, k);
    print3DMatrix(matriz, m, n, k);
    free3DMatrix(matriz, m, n);
}