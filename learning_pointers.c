/* POINTERS
- variable like reference that holds  memory address to another variable, array, etc.
- some tasks are performed more easily with pointers
* = indirection operator (value at address)

benefits
- we can create data structures, return multiple values with a function, search/sort large data more easily
- dynamic memory allocation*/



#include <stdio.h>

void printAge(int *pAge);

int main(){
    int age = 21;

    printf("address of age: %p\n", &age); // displaying adddress of variable
    // %p format to display address, & for address preceeding variable
    printf("value of age: %d\n", age); // value at this address

    int *pAge = &age;  // datatype of variable preceeding indirection operator
    // pointers should always be assigned address of a variable not the variabe (value) directly

    // naming convention - *(lowercase p)(variable name with first letter uppercase)
    // we can declare and intialize seperately for pointrs as well 
    //(good covention is assigning a pointer value NULL if only declaring and initialising)

    printf("value of pAge: %p\n", pAge); // pointer storing address

    // in case we only know the address but not the value of the variable we can access the value 
    // the pointer and variable memory addresses are different 
    printf("value at stored address: %d\n", *pAge); // to dereference a pointer precced name with indirection operator


    // indirection operator is used when declaring a pointer and accessing value at stored address
    // be careful with keeping data type same for pointer and variablbe it is pointing to

    // & preceed for address of variable
    // &pAge for address of pointer and pAge for address of variable 
    // *pAge for dereferencing (no longer using %p) - for getting the value

    printf("size of age: %d bytes\n", sizeof(age));
    printf("size of pAge(pointer): %d bytes\n", sizeof(pAge));

    printAge(pAge);

    //going through an array using pointers
    int a[] = {1, 2, 3, 5, 5};
    int n = 5;
    int *p = &a[0];
        while(p < &a[n]) // while pointer address less than address of a[5]
        {
            printf("%d\t\n", *p);
            p++;
            // loop breaks when p = &a[5]
        }

        // printing first and last element 
        int *pA = &a[0];
        int *qA = &a[n - 1];
        while(pA <= qA){
            if(pA == qA){
                printf("elements: %d\n", *pA);
                break;
            }
            printf("elements: %d %d\n", *pA, *qA);
            pA++;
            qA--;
        }

    int *pa = &a[0];
    int *q;
    int dup = 0;
    while(pa - &a[0] < n)// the distance we have gone is less than n
    {
        q = pa + 1; // setting q as pa would also work
        while(q - &a[0] < n){
            if(*pa == *q){
                dup = 1;
            }
            q++;
        }
        pa++;
    }
    printf("present: %d", dup);

    int array1[10]; // this has values from indexes 0  - 9 so if we ry to access values 
    // outside of this range we get a segmentation error
    // name of array is address of first element
    // to get array1[3] == *(array1 + 3)

    char s[10];//n chars == n + 1 sized array
    int n = 10;

    // Readlines function:
    /* 
    Inputting w/o pointers
    last char is '\0' (null character) and in n + 1 size array there are n chars
    we use get char/scanf in a while loop
    */
   char ch = getchar();
   int i = 0;
   while(ch != '\n' && i < n - 1) // while ch is not a newline (until enter key is pressed) and i is less then n - 1 
   {// whitespace in between is also counted as a char (included in n)
    s[i] = ch;
    i++;
    ch = getchar(); // need to include again in loop as getchar gets char by char
    // otherwise we can have it in while condition ((ch = getchar()) != '\n' && i < n - 1)
   }
   s[i] = '\0'; // need to include null char for it to be a string variable
    printf("%s\n", s);

    // Inputting with pointers (less time to run)
    char p[10];
    char ph;
    char *pP = p;
    while((ph = getchar()) != '\n' && pP < p + n - 1) // pP < p + n - 1 == pP < &p[0] + n - 1
    // since comparison cannont occur between pointer and int (we need to compare with address pointer arihmetic)
    {*pP++ = ph;}
    *pP = '\0';

    pP = p;
    int size = 0; // to keep track of second input 
    while((ph = getchar()) != '\n' && pP < p + n - 1) 
    {*pP++ = ph;
        size++; // so that we only print what is being inputed in this loop (to keep track)
        }
    *pP = '\0';

    //printing w/o  pointers
    printf("%s\n", p); // we print up until the null character

    // printing with pointers
    pP = p; // we need to initialize again
    while(pP < p + size && *p != '\0') 
    // when we are taing input twice and printing twice this form of printing prints everyting in array again
    // so we include a size operator in second input code and in print code we set that as a condition along with until the null char 
    {
        printf("%c", *pP);
        pP++;
    }
    printf("\n");


    return 0;
}

// we can also pass pointers as arguments
void printAge(int *pAge){
    printf("you are %d years old\n", *pAge); // dereferencing (access/modification)

}


