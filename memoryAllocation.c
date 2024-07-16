#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

struct car {
    int vin;
    char name[26];
};

void add_item(struct car *d, int size, int *quantity){
    // quantity < size 
    printf("Enter vin number: ");
    scanf("%d", &(d + *quantity)->vin); // adding to next position

    printf("Enter name: ");
    scanf("%s", (d + *quantity)->name);

    *quantity  = *quantity + 1;

}

int main(){

// MEMORY ALLOCATION

// sp (stack pointer), hp (heap pointer)
/*
- 3 functions:
1. malloc (imp) - giving space to a pointer
2. calloc
3. realloc
4. free - freeing that space */

int *p = malloc(sizeof(int)); // allocating size of one int
*p = 10;
free(p);

int n; // each int is 4 bytes so if we want to allocate size for n int we need to multiply n * size of one int (4)
n = 2;
// creating a dynamic array
int *q = malloc(sizeof(int)*n); // allocating size of 2 int
// ponter always points to address of first int (first element in array)
q[0] = 10; // same as *(q)
q[1] = 15; // *(q + 1)
// we just created an array of 2 int
free(q); // freeing up the space 

struct car *c = malloc(sizeof(struct car)); // allocating space equal to members in car 
// here c is allocated more than 30 bytes (4 for int vin and 26 for char name and some extra space)

(*c).vin = 15; // c->vin = 15;
printf("vin: %d\n", c->vin);

int size = 2; // max size of list 
struct car *list = malloc(sizeof(struct car*) * size); // making size amount of struct objects
// we always allocate size to double the amount we need and (later shrink it) ie 2n 
int option;
int quantity = 0; // items in list 

while(1 == 1) // infinite loop
{
    printf("Enter option: ");
    scanf("%d", &option);
    switch(option){
    case 1:
        for(int j = 0; j < quantity; j++){
            printf("vin: %d, name: %s\n", list[j].vin, list[j].name);
        }
        break;
    case 2:
        // checking if array is full
        if(quantity == size){
        // array is full so we need to reallocate more space
        struct car* new = malloc(sizeof(struct car) * size * 2); // we created new array twice the size
        // so we have to copy previous content to new array
        int i = 0;
        while(i < quantity){
            new[i] = c[i];
            i++;
        }
        free(list); // freeing older list
        list = new; // older list is now new list with more space
        size *= 2; // increasing size
        }
        add_item(list, size, &quantity); 
        break;
    
}

}

free(list); // free list at end
 
return 0;
}