#include <stdio.h>

int *largest(int array[], int size){
    int *largest = array; // pointing to first element in array

    int *p = array;

    // using pointers to iterate over arrays
    while(p <= &array[size - 1]){
        if(*p >= *largest) // checking if value of each element is >= array[0]
        {
            largest = p;
        }
        p++; // incrementing pointer to move to next element address
    }
    return largest; // returning pointer pointing to largest element
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sort(int array[], int size){
    int temp;
    // 1. base case
    if(size == 1) return;
    // 2. swap
    swap(largest(array, size), &array[size - 1]); 
    // since function largest returns a pointer we can past it as an argument for a pointer parameter
    sort(array, size - 1);
    
}


int main(){
    
    int array[] = {5, 7, 8, 3, 2, 1, 4, 6};
    int size = sizeof(array)/sizeof(array[0]);
    sort(array, size);
    for(int i = 0; i < size; i++){
        printf("%d\t", array[i]);
    }
    
    return 0;
}

