#include <stdio.h>


// Multiplies two integers
int multiplyNumbers(int number1, int number2) {

    // Result variable is the integer product of arguments number1 and number2
    int result = number1 * number2;

    // Returns result variable
    return result;

}

// Main function
int main(void) {

    // Instantiates number1 and number 2 as integers
    int number1;
    int number2;

    // Prompt user for input
    printf( "Enter two integers to be multuplied\n[format: a b]\n-> ");

    // Assign input to number1 and number2
    scanf( "%d %d", &number1, &number2 );

    // Call multiplyNumbers() using the input as arguments and save it as product integer
    int product = multiplyNumbers(number1, number2);

    // Print product varibale
    printf( "%d", product );

    return 0;

}