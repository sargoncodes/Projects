#include <stdio.h>

// Create a structure called Complex
typedef struct Complex {

    // Store two double variables, real and imaginary
    double real;
    double imaginary;

} COMPLEX; // Refer to it as COMPLEX

int main(void) {

    // Create three child structures to store 3 different sets of real and imaginary values
    COMPLEX c1 = {.real = 48.35, .imaginary = 27.86};
    COMPLEX c2 = {.real = 24.91, .imaginary = 16.17};
    COMPLEX c3 = {.real = 19.99, .imaginary = 7.48};

    // Instantiate child structure called diff
    COMPLEX diff;

    // Find the difference of all child classes' real and imaginary values then store them as diff's real and imaginary values
    diff.real = ( c1.real - c2.real - c3.real );
    diff.imaginary = ( c1.imaginary - c2.imaginary - c3.imaginary );

    // Print out the real and imaginary values stored in diff
    printf( "\nResult: %.2lf - %.2lfi\n", diff.real, diff.imaginary );

    return 0;

}