#include <stdio.h>

int main(void) {
    //Initialize number varibale
    int number;    

    //Prompt for number
    printf("Insert a number to check if it is positive, negative, or neither: \n");

    //Assign input to number variable
    scanf("%d", &number);

    //Check if number is greater than or less than 0 and prints the result
    if( number > 0 ) printf( "\nYour number is positive" );
    else if( number < 0) printf( "\nYour number is negative" );
    else printf("\nYour number is 0"); //If neither, the result must be 0

    return 0;
}