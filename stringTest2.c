#include <stdio.h>

//function to return a string literal
char *getString() {
    return "Returned string literal";
}



int main(){
// *str
char *str ;

//assign a string literal to the pointer
str = "Hello, World!";
printf("String: %s\n", str);

//attempt to modify the string literal (this is undefined behavior and may cause a crash)
// str[0] = 'h'; // Uncommenting this line may cause a segmentation fault

str = getString();
printf("String from function: %s\n", str);

    return 0;
}