#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// QUESTION 1:
void property_3025(int n){
    int first_two_digits = n / 100;
    int last_two_digits = n % 100;

    int addition = first_two_digits + last_two_digits;
    int square = addition * addition;

    if(square == n){
        printf("Yes, it complies with the property\n");
    }

    else{
        printf("Does not comply with the property\n");
    }
}

// QUESTION 2
void capicua(int n){
    int aux = n;
    int number = 0;;
    while (aux != 0)
    {
        int residue = aux % 10;
        number =  number * 10 + residue;
        aux = aux / 10;
    }
    
    if(number == n){
        printf("the number is capicua\n");
    }
    else{
        printf("the number is not capicua\n");
    }
}

//QUESTION 3
void swap(int *a, int *b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

//QUESTION 4
void menu(){
    int option;
    printf("Choose operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    scanf("%d", &option);
    int num1, num2;
    if(option == 1){
        printf("Please enter two numbers: ");
        scanf("%d %d", &num1, &num2);
        printf("the addition is : %d\n", num1 + num2);
    }
    else if(option == 2){
        printf("Please enter two numbers: ");
        scanf("%d %d", &num1, &num2);
        printf("the Subtraction is : %d\n", num1 - num2);
    }
    else if(option == 3){
        printf("Please enter two numbers: ");
        scanf("%d %d", &num1, &num2);
        printf("the Multiplication is : %d\n", num1 * num2);
    }
    else if(option == 4){
        printf("Please enter two numbers: ");
        scanf("%d %d", &num1, &num2);
        printf("the Division is : %d\n", num1 / num2);
    }
    else{
        return;
    }
}

//QUESTION 5
void AbsoluteDifference(int list[], int n){
    if(n < 1){
        printf("the list is empty\n");
        return;
    }

    int min = list[0];
    int max = list[0];

    for(int i = 0; i < n; i++){
        if(list[i] < min){
            min = list[i];
        }
        if(list[i] > max){
            max = list[i];
        }
    }

    if(max == min){
        printf("The absolute difference is 0\n");
        return;
    }

    int difference = abs(max - min);
    
    printf("The absolute difference is %d\n", difference);
}

//QUESTION 6
int existsInSet(int set[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (set[i] == value) {
            return 1;
        }
    }
    return 0;
}

void printList(int list[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

void intersectionSet(int set1[], int set2[], int size1, int size2) {
    int result[100];
    int count = 0;

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (set1[i] == set2[j] && !existsInSet(result, count, set1[i])) {
                result[count++] = set1[i];
                break;
            }
        }
    }

    printf("Intersection: ");
    printList(result, count);
}

void unionSet(int set1[], int set2[], int size1, int size2) {
    int result[100];
    int count = 0;

    for (int i = 0; i < size1; i++) {
        if (!existsInSet(result, count, set1[i])) {
            result[count++] = set1[i];
        }
    }

    for (int i = 0; i < size2; i++) {
        if (!existsInSet(result, count, set2[i])) {
            result[count++] = set2[i];
        }
    }

    printf("Union: ");
    printList(result, count);
}

void differenceSet(int set1[], int set2[], int size1, int size2) {
    int result[100];
    int count = 0;

    for (int i = 0; i < size1; i++) {
        if (!existsInSet(set2, size2, set1[i]) && !existsInSet(result, count, set1[i])) {
            result[count++] = set1[i];
        }
    }

    printf("Difference (Set1 - Set2): ");
    printList(result, count);
}


int main(){
    //QUESTION 1
    int number = 3025;
    property_3025(number);

    //QUESTION 2
    int capicuaNumber = 12321;
    capicua(capicuaNumber);

    //QUESTION 3
    int number1 = 125;
    int number2 = 305;
    printf("number 1: %d\n", number1);
    printf("number 2: %d\n", number2);
    swap(&number1, &number2);
    printf("number 1 after swap: %d\n", number1);
    printf("number 2 after swap: %d\n", number2);

    //QUESTION 4
    menu();

    //QUESTION 5
    int list[] = {8, 2, 7, 5, 3, 4, 2, 9};
    int size = sizeof(list) / sizeof(list[0]);
    AbsoluteDifference(list, size);

    //QUESTION 6
    int set1[] = {8, 2, 7, 5, 3, 4, 9};
    int set2[] = {1, 5, 6, 9, 1};

    int size1 = sizeof(set1) / sizeof(set1[0]);
    int size2 = sizeof(set2) / sizeof(set2[0]);

    intersectionSet(set1, set2, size1, size2);
    unionSet(set1, set2, size1, size2);
    differenceSet(set1, set2, size1, size2);
}