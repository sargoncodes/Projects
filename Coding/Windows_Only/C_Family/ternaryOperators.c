#include <stdio.h>

int main(void) {

    // Instantiate "number" as an integer
    int number;
    
    // Prompt user for input
    printf( "Enter a number to see if it is even or odd\n" );

    // Store input in number
    scanf("%d", &number);
    
    (number % 2 == 0) ? printf( "\nYour number is even") : printf( "Your number is odd" );
    
    return 0;

}