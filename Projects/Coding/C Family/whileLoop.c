#include <stdio.h>

int main(void) {

    // Initialize number, product, and iter as int variables
    int number;
    int product;
    int iter = 11; // Assign iter as 11

    // Prompt user for input
    printf( "\nWhat number do you want to find the multiplication table of?\n" );

    // Assign input to 0
    scanf( "%d", &number );

    // Loop until iter reaches 0
    while( iter > 1 ){

        // Incriment iter
        --iter;

        // Find the product of this iteration
        product = number * iter;

        // Print result
        printf( "\t%d * %d = %d\n", number, iter, product );

    }

    return 0;

}
