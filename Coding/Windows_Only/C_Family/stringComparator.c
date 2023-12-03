#include <stdio.h>
#include <string.h>

int main(void) {

    // Initialize two string variable arrays
    char str1[50];
    char str2[50];

    // Prompt user for first input
    printf( "\nProvide the first string:\n" );

    // Collect the input and assign it to str1
    fgets( str1, sizeof(str1), stdin );

    // Remove tailing newline that fgets() adds
    str1[strcspn(str1, "\n")] = '\0';

    // Prompt user for second input
    printf( "\nProvide the second string:\n" );

    // Collect this input and assign it to str2
    fgets( str2, sizeof(str2), stdin );

    // Remove tailing newline that fgets() adds
    str2[strcspn(str2, "\n")] = '\0';

    // Compare the sizes of both strings and print out the larger string
    ( strlen(str1) > strlen(str2) ) ? printf( "\n\"%s%\" is larger\n", str1 ) : printf( "\n\"%s%\" is larger\n", str2 );

    return 0;

}