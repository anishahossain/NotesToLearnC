#include <stdio.h>
#include <stdbool.h>

void sort(int array[], int size)
{
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - 1; j++){
            // sorting the array - ascending order
            if(array[j] > array[j + 1]){ // means if number on left is greater than number on right
            int temp = array[j];
            array[j] = array[j + 1];
            array[j + 1] = temp;
            }
        }
    }
}

void sortChar(char array_char[], int size)
{
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - 1; j++){
            // sorting chr=aracters - ascending order
            if(array_char[j] > array_char[j + 1]){ // means if char on left is greater than char on right
            char temp_char = array_char[j];
            array_char[j] = array_char[j + 1];
            array_char[j + 1] = temp_char;
            }
        }
    }
}

void printArray(int array[], int size){
    for(int i = 0; i < size; i++){
        printf("%d\n", array[i]);
    }
}

void printArrayChar(char array_char[], int size){
    for(int i = 0; i < size; i++){
        printf("%c\n", array_char[i]);
    }
}

int main(){

    int array[] = {9, 1 , 8, 7, 4, 5, 6, 3, 2};
    char array_char[] = {'A', 'V', 'F', 'O', 'P', 'E'};
    int size = sizeof(array)/sizeof(array[0]);

    sort(array, size); // square brackets are no longer needed in call to function 
    printArray(array, size);

    sortChar(array_char, size); 
    printArrayChar(array_char, size);

    return 0;}
