#include <stdio.h>
#include <string.h>

//created outside main function
struct fullName{
    char firstName[26];
    char lastName[26];
    int age;
}; // semicolon after 

struct Eg{
    char name[26];
    int value;
};


int main(){

    struct fullName name; // name here is a char array[] (from struct)
    // datatype of name is struct variable is the struct
    strcpy(name.firstName, "Anisha"); // struct.StructName is how to use them everywhere to do something
    printf("%s\n", name.firstName);

    struct fullName name1;
    name1 = name; // .struct_variable is not neede between struct variables assignment
    printf("%s\n", name1.firstName);

    struct fullName name2;
    strcpy(name2.lastName, "Hossain");

    struct fullName lastnames[10]; // names is a 2D array since the struct is already a char array[]
    int i = 0;
    while (i < 3) // using loops for structs
    {
        lastnames[i] = name2; // .struct_variable is not neede between struct variables assignment
        printf("%s\n", lastnames[i].lastName); // we add .structobject after [index]
        i++;
    }

    struct fullName *pF; // pointer type is also struct structName

    struct Eg example; // this is a struct element
    struct Eg number;
    strcpy(example.name, "Anisha");
    number.value = 12;

    printf("example: %s, number: %d\n", example.name, number.value);

    struct Eg* p = &example;
    // here p points to struct item example not to example.MEMBER   
    // (*p).name (is the same as example.name) is not an address
    // so passing to scanf as an argument we need to use the and operator (&)

    // CHECK FROM HERE AND CORRECT NOTES
    printf("Enter: ");
    scanf("%s", p->name); // & not needed as name is an array
    printf("Enter value: ");
    scanf("%d", &p->value); // & needed as value is not an array (an int)

    // & usage in scanf and fscanf depends on the struct member not on the struct object 
    // IN FSCANF & NEEDED BEFORE POINTER->MEMBER if member is not an array type

    printf("p->name: %s\n", p->name);
    printf("p->value: %d\n", p->value);
    printf("(*p).name: %s", (*p).name);
    // both output same hence using p->structmember is much more efficient


    return 0;
}