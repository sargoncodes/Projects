#include <stdio.h>

int main(void) {

    // Initialize number variable as int
    int number;

    // Start infinite loop
    while( 1 == 1 ){

        // Prompt user for input
        printf( "\nEnter a number\n" );

        // Assign input to number varibale
        scanf( "%d", &number );

        // if number is positive, break
        if ( number > 0 )  {
            
            printf("\nPositive value");
            
            break;
            
        }

        // if number is even, continue
        else if( number % 2 == 0 )  {
            
            printf("\nNegative even");
            
            continue;
            
        }

        // if number is odd, print value and continue
        else {

            printf( "%d", number );

            continue;

        }

    }

    return 0;

}