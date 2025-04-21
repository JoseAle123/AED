#include <stdio.h>
#include <stdbool.h>
#define SIZE 3

//QUESTION 2
void printMatrix(int matrix[][SIZE], int size){ //print matrix with same dimensions
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

bool matrixSymmetric(int matrix[][SIZE], int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(matrix[i][j] != matrix[j][i]){
                return false;
            }
        }
    }
    return true;
}

//QUESTION 3
void transposed(int matrix[][SIZE], int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            matrix[i][j] = matrix[j][i];
        }
    }
}

//QUESTION 4
void printMatrix2(int row, int col, int matrix[][col]){  //print matrix with different dimensions
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void copy(int matrix1[][SIZE], int matrix2[][SIZE], int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            matrix1[i][j] = matrix2[i][j];
        }
    }
}

void determinant(int matrix[][SIZE], int size){
    int matrixAux[size + 2][size];
    copy(matrixAux, matrix, SIZE);
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < size; j++){
            matrixAux[i + size][j] = matrix[i][j];
        }
    }
    printMatrix2( size + 2, size, matrixAux);

    int posDiagonal = 0, negDiagonal = 0;

    // calculate positive diagonals
    for (int i = 0; i < size; i++) {
        int mult = 1;
        for (int j = 0; j < size; j++) {
            mult *= matrixAux[i + j][j];
        }
        posDiagonal += mult;
    }

    // calculate negative diagonals 
    for (int i = 0; i < size; i++) {
        int mult = 1;
        for (int j = 0; j < size; j++) {
            mult *= matrixAux[i + j][size - 1 - j];
        }
        negDiagonal += mult;
    }

    int det = posDiagonal - negDiagonal;
    printf("Determinante: %d\n", det);
}

//QUESTION 5
void productMatrix(int row1, int row2, int col1, int col2, int matrix1[][col1], int matrix2[][col2]) {
    if (col1 != row2) {
        printf("Matrices CANNOT be multiplied\n");
        return;
    }

    int matrixAux[row1][col2];

    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            matrixAux[i][j] = 0;  
        }
    }

    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            for (int k = 0; k < col1; k++) {
                matrixAux[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    printMatrix2(row1, col2, matrixAux);
}



int main(){
    int matrix[SIZE][SIZE] = {
        {1, 2, 3},
        {2, 1, 0},
        {3, 0, 1}
    };

    //QUESTION 2
    printf("matrix: \n");
    printMatrix(matrix, SIZE);
    if(matrixSymmetric(matrix, SIZE)){
        printf("the matrix is symmetrical\n");
    }
    else{
        printf("the matrix is not symmetrical\n");
    }

    //QUESTION 3
    printf("matrix before transposed:\n");
    printMatrix(matrix, SIZE);
    transposed(matrix, SIZE);
    printf("matrix after transposed\n");
    printMatrix(matrix, SIZE);

    //QUESTION 4
    printf("determinant of matrix: \n");
    determinant(matrix, SIZE);

    //QUESTION 5
     int row1 = 2, col1 = 3;
     int row2 = 3, col2 = 2;
 
     int A[2][3] = {
         {1, 2, 3},
         {4, 5, 6}
     };
 
     int B[3][2] = {
         {7, 8},
         {9, 10},
         {11, 12}
     };

     printf("product of two matrix: \n");
     productMatrix(row1, row2, col1, col2, A, B);
}

