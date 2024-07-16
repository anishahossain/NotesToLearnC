#include <stdio.h>
// this line of code is needed to write and run code for c
#include <stdbool.h> // to include usage of boolean values
#include <string.h>

int main(){
// escape sequences
    printf("Hello\nWorld\n");
    printf("I like pizza\n");
    printf("1\t2\t3\t\n");
    printf("\"Anisha\"\n");

// variables 
    int x; // declaration
    x = 123; // intialization
    int age = 19; //both combined %d
    float gpa = 3.93; // float %f
    double d = 1.234567890; // have double the precision of a float %l f
    char letter = 'C'; // single character %s
    char my_name[] = "Anisha"; // array of characters (always use " " double quotes with arrays)
    // character arrays cannot be incomplete and need to be assigned sth (like empty string " ")

    // there are many more data types in notes explained   
    printf("Hi, my name is %s\n", my_name); // format specification for printing
    
    float item1 = 4.75;
    float item2 = 2.34;
    float item3 = 6.734;
    // for decimal precision we use %.(number of digits)(special data type character)
    // default alignment is right (extra whitepsace befor data)
    // left alingment puts data onleft (before extra whitespace)
    
    printf("price is $%-8.2f\n", item3); // left alinged, 8 mediem field length (char space) and 2 dp

    const float PI = 3.14159;

    // taking user input (terminal window)
    int user_age;
    char name[25]; // inside square brackets is the bite size specified (max)
    printf("What is your name?\n");
    scanf("%s", &name);
    printf("Hi %s\n", name);

    printf("How old are you?\n");
    scanf("%d", &user_age);
    printf("You are %d years old\n", user_age);



    // using fgets for input including whitespace
    // fgets function includes \n at the end 
    char full_name[100]; // always define size for input of character array
    printf("What is your full name? ");
    fgets(full_name, 100, stdin);
    full_name[strlen(full_name)-1] = '\0'; // to get rid of the newline

    printf("hello %s, nice to meet you", full_name);

    // if - else if - else statements are the same as python 
    // if/else if/else(condition){code for specefic condition when true}

    // switches are similar tp match case
    /* switch(variable){
        case 'A':
            specific code
            break (to exit out of a switch so that the other cases are not also executed)
        default:
            code for when there is o case match (no break statement needed)
    */

   /* logical operators = && (AND) (can be used multiple times - all conditions need to be true), 
   Boolean value (true or false), || (OR)(at least one condition is true)
   */
  // not operator (!)
    bool sunny = true;
    if(!sunny) // !sunny means condition is not sunny (sunny == false)
    {
        printf("\nIt is not sunny outside"); // code will be executed if sunny == false
    }
    else{
        printf("It is sunny outside");
    }
    return 0;
}
