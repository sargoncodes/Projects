#include <stdio.h>

// Create enumeration Week containing the days of the week as variables
enum Week {

    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,

};

int main(void) {

    // Isolate the weekend days from the enum and store them as weekend1 and weekend2
    enum Week weekend1 = Sunday;
    enum Week weekend2 = Saturday;

    // Print results to screen
    printf( "\n\n\t--CONVERSION TABLE--\n\t->Sunday = 0\n\t->Monday = 1\n\t->Tuesday = 2\n\t->Wednesday = 3\n\t->Thursday = 4\n\t->Friday = 5\n\t->Saturday = 6\n\t---------------------\n\n\nWeekend value one: %d\nWeekend value two: %d\n\n", weekend1, weekend2 );

    return 0;

}