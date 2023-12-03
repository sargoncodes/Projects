#include <stdio.h>

int main(void) {

    // Instantiate month variable as an int
    int month;

    // Prompt user for input
    printf( "Choose number to see corresponding month\n" );

    // Store input in month
    scanf( "%d", &month);

    // Find determine which month corresponds with the user's input
    switch(month){
        case 1: 
        printf( "January" );
        break;

        case 2: 
        printf( "Febuary" );
        break;

        case 3: 
        printf( "March" );
        break;

        case 4: 
        printf( "April" );
        break;

        case 5: 
        printf( "May" );
        break;

        case 6: 
        printf( "June" );
        break;

        case 7: 
        printf( "July" );
        break;

        case 8: 
        printf( "August" );
        break;

        case 9: 
        printf( "September" );
        break;

        case 10: 
        printf( "October" );
        break;

        case 11: 
        printf( "November" );
        break;

        case 12: 
        printf( "December" );
        break;

        default :
        printf( "Invalid answer" );
        break;
    };

    return 0;

}