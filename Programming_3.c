#include <stdio.h>
#define SIZE 3

//QUESTION 1
void printMatrix(int matrix[][SIZE], int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void permutationMatrix(int matrix[][SIZE], int size){
    for(int i = 0; i < size; i++){
        int row = 0;
        int col = 0;
        for(int j = 0; j < size; j++){
            row = row + matrix[i][j];
            col = col + matrix[j][i];
        }
        if((row > 1) || (col > 1)){
            printf("no, it is not matrix permutation\n");
            return;
        }
    }
    printf("yes, it is a matrix permutation\n");
}

//QUESTION 2
void copy(char str1[], char str2[]){
    int i = 0;
    while (str1[i] != '\0')
    {
        str2[i] = str1[i];
        i++;
    }
    str2[i] = '\0';
}

//QUESTION 3
int length(char str[]){
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

void reverse(char str[]){
    int lengthChar = length(str);
    for(int i = 0; i < lengthChar / 2; i++){
        char tmp = str[i];
        str[i] = str[lengthChar - i - 1];
        str[lengthChar - i - 1] = tmp;
    }
}

//QUESTION 4
int compare(char str1[], char str2[]){
    int i = 0;
    int j = 0;
    while (str1[i] != '\0' && str2[j] != '\0')
    {
        if(str1[i] > str2[j]){
            return 1;
        }
        else if(str1[i] < str2[j]){
            return -1;
        }
        i++;
        j++;
    }

    if(str1[i] == '\0' && str2[j] == '\0'){
        return 0;
    }
    else if(str1[i] == '\0' && str2[j] != '\0'){
        return -1;
    }
    else if(str1[i] != '\0' && str2[j] == '\0'){
        return 1;
    }
}

int main() {
    //QUESTION 1
    int matrix[SIZE][SIZE] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    printMatrix(matrix, SIZE);
    permutationMatrix(matrix, SIZE);

    //QUESTION 2
    char str1[] = "Hello world";
    char str2[] = "";
    printf("str2 before copy: %s\n", str2);
    copy(str1, str2);
    printf("str2 after copy: %s\n", str2);

    //QUESTION 3
    char str3[] = "MC202";
    printf("str3 before reverse: %s\n", str3);
    reverse(str3);
    printf("str3 after reverse: %s\n", str3);

    //QUESTION 4
    char str4[] = "appleTR";
    char str5[] = "apple";
    int compareChar = compare(str4, str5);
    if(compareChar == 1){
        printf("str4 is greater than str5 lexicographically\n");
    }
    else if(compareChar == -1){
        printf("str5 is greater than str4 lexicographically\n");
    }
    else{
        printf("both are the same\n");
    }
}