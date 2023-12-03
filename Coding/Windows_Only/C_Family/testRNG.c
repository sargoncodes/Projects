#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    printf( "\nLet's see how lucky you are...\n\n" );

    srand(time(NULL));

    int randomNumber = rand() % 100;
    ++ randomNumber;

    if (randomNumber == 1) {

        printf( "\nYOU'VE BEEN BLESSED BY RNGESUS (1%% chance)\n\n" );

    } else if (randomNumber > 1 && randomNumber < 11) {

        printf( "\nYou're pretty lucky (10%% chance)\n\n" );

    } else if (randomNumber > 10 && randomNumber <= 60) {

        printf( "\nYou're a little on the lucky side (~50/50)\n\n" ) ;

    } else if (randomNumber > 60 && randomNumber <= 90) {

        printf( "\nYou're looking a little unlucky (~30%% chance)\n\n" );

    } else if (randomNumber > 90 && randomNumber < 100) {

        printf( "\nYou're pretty unlucky (~10%% chance)\n\n" );

    } else if (randomNumber == 100) {

        printf( "\nRNGesus hates you, good luck (1%% chance)\n\n" );

    } else { printf( "\nYour code is bad, the number is %d\n\n", randomNumber ); };

    return 0;

}