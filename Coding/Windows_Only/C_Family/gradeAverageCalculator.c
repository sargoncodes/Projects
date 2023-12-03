#include <stdio.h>

// Create an array with 5 positions
int grades[5];

// Create a function for gathering grades
void gather() {

    // Loop through the array
    for( int i = 0; i < 5; i++ ){

        // Prompt the user for input
        printf( "\nInput grade for subject %d:\n", i + 1 );
        
        // Take an input for each position of the array
        scanf( "%d", &grades[i] );

    }

}

// Create a function for calculating the average
void calculate() {

    // Initialize total as integer 0
    int total = 0;

    // Loop through grades
    for( int i = 0; i < 5; i++ ){

        // Add current iteration's grade to total
        total = total + grades[i];

    }

    // Print the average of grades
    printf( "\nAverage: %%%.2lf", (double)total / 5.0 );

}

int main(void) {

     // Call the gather() function to fill the array
    gather();

    // Call the calculate() function to print the result
    calculate();

    return 0;

}