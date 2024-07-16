#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* quicksort takes parameters:
1. *base - base of array (pointer pointing to first element of array)
2. number of elements to be sorted
3. size of each element (to allow memory allocaion)
4. compare function - each with a different prototype that we create
*/

int compareInt(const void* p1, const void* p2){
    /* 
    return -1 if p < q
    return 0 if p = q
    return 1 if p > q
    */
// the order is always -1, 0, 1 so if we appoint 1 to > and -1 to < then it will be descending order 

// we need to type cast the void pointers (with const!!! as we should not change values)
   const int *p = p1;
   const int *q = p2;
   if(*p < *q){
    return -1;
   }
   if(*p == *q){
    return 0;
   }
   if(*p > *q){
    return 1;
   }

}

int strCompare(const void* s1, const void* s2){
    const char** p = s1; // since hey are 2D arrays hence a double pointer
    const char** q = s2;

    if(strcmp(*p, *q) < 0){
    return -1;
   }
   if(strcmp(*p, *q) == 0){
    return 0;
   }
   if(strcmp(*p, *q) > 0){
    return 1;
   }

}

int main(){
    int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    qsort(array, 10, sizeof(int), compareInt);
    //  we do not need to pass arguments for compareInt as its a fucntion pointer (address)

    int i = 0;
    while(i < 10){
        printf("%d\t", array[i]);
        i++;
    }

// for strings
    char **str; // double pointer (pointer to a pointer)

    str = malloc(10 * sizeof(char *)); // size of character array
    // creates pointer to a pointer hence array of 10 pointers 
    // basically creates a dymnamic 2D array as each pointer is to a character in string

    int j = 0;
    while(j < 3){
        char* temp = malloc(100 * sizeof(char));
        scanf("%s", temp);
        str[j] = temp;
        j++;
    }

    j = 0;
    while(j < 3){
        printf("%s\t", str[j]);
        j++;
    }

    qsort(str, 3, sizeof(char*), strCompare);

    printf("\nafter qsort:\n");
    j = 0;
    while(j < 3){
        printf("%s\t", str[j]);
        j++;
    }

    return 0;

}