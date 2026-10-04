#include <stdio.h>

//function to return a string literal
/*
char *getString() {
    return "Returned string literal";
}
*/
int main() {
    // examples ofstring arrays and pointers
    char str1[] = "Hello, World!";
    /* string array, str points to the first character of the array
        the compiler allocates memory on the stack for the array and copies the string literal into that memory.
        You can modify the contents of the array, but you cannot change the address that str1 points to.
    */
     char *str2 = "Hello, C!";// pointer to a string literal
     /* This creates a pointer that points directly to the string literal stored in read-only memory. 
        You must not try to change the characters (e.g., str2[0] = 'M'; is*/

    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);

    //alter str1 and str2   
    str1[0] = 'h'; // Change the first character of str1
    // str2[0] = 'c'; // This will cause a segmentation fault because str2 points to a string literal, which is read-only
    //*str2 = 'c'; // This will also cause a segmentation fault for the same reason
    printf("String 1 after alteration: %s\n", str1);
    printf("String 2 after alteration: %s\n", str2);

        str2 = str1;
    printf("String 2 after redirection: %s\n", str2);
    str2[0] = 'H'; // Change the first character of str2
    printf("String 1 after altering str2: %s\n", str1);

    str2 = "New much longer string";
    printf("String 2 after redirection: %s\n", str2);


    // pass a string by reference to a function
    void printString(char *str1) {
        printf("Inside function: %s\n", str1);
        str1 = str2; // redirect str1 to point to str2
        printf("Inside function after redirection: %s\n", str1);
    }
    printString(str1);

    char *str3;
    str3 = getString();
    printf("String 3: %s\n", str3);
    
    return 0;
}