#include <stdio.h>

int main(void) {

    // Instantiate string varibale
    char name[50];

    // Prompt user for input
    printf( "Enter your name:\n" );

    // Assign user input
    fgets(name, sizeof(name), stdin);

    // Change first character of name to X
    name[0] = 'X';

    // Print result
    printf( "\n%s\n", name );

    return 0;

}