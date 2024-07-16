#include <stdio.h>
#include <stdlib.h>

// Traversal: 1. Each ds (datastructure) has its own mechanism to access values
// pointers allow us to reduce the amount of instructions
    
int *largest(int *array, int n){
    int i = 0;
    int *largest = array;
    int *p = array;
    while(i < n){
        if(*p > *largest){
            *largest = *p;
        }
        p++;
        i++;
    }
    return largest; // function is declared to return int* (pointer to int)

}

int main(){
    int array[] = {2, 6, 110, 3, 27, 9};
    int n = 6;
    printf("%d", *(largest(array, n))); // type casting the return from function so that there is no warninig*/

    int array[2][2] = {{1,2}, {3,4}};
    // to represent an array of innters we use integer pointers
    // to represent an array of pointers (2D array) we use integer pointer pointer

    int *p = array[0]; // same as using a double pointer int **p = array;
    int r = 2, c = 2; // row = 2 column = 2
    /* 
        *p = 1
        *(p + 1) = 2
        *(p + 2) = 3
        *(p + 3) = 4
      if we know our rows and columns we can access 2D arrays 
    */
   while(p < &array[0][0] + r*c) // we cannot use r*c directly as pointers cannot be compared to int 
   {
    printf("%d \n", *(p));
    p++;
   }
   return 0; 
}
