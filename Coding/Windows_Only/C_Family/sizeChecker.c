#include <stdio.h>

int main(void) {

    // Instantiate datatype and check integer variables, storing 1 into check
    int datatype;
    int check = 1;

    // Check what datatype the user wants to find the size of
    printf( "\nWhat datatype do you want to find the size of? (Choose a number)\nOptions = [1. int, 2. float, 3. bool, 4. char]\n\n-> " );

    while( check == 1 ) {

        // Store user input to datatype variable
        scanf( "%d", &datatype );

        // Based on if user's input is valid, decide to either print out the corresponding answer and break, or iterate again until valid input is read
        switch(datatype){

            case 1:
            printf( "\nint = %d bytes\n\n", sizeof(int) );
            check = 2;
            break;

            case 2:
            printf( "\nfloat = %d bytes\n\n", sizeof(float) );
            check = 2;
            break;

            case 3:
            printf( "\nbool = %d byte\n", sizeof(_Bool) );
            check = 2;
            break;

            case 4:
            printf( "\nchar = %d bytes\n\n", sizeof(char) );
            check = 2;
            break;

            default :
            printf( "\nInvalid input, choose an integer from the list:\n[1. int, 2. float, 3. bool, 4. char]\n\n->" );
            break;

        };

    };
    
    return 0;

}