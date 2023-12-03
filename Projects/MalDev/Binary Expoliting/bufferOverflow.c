#include <stdio.h>
#include <unistd.h>

// Function used to read user's input and to spit it back out with byte size //! Purposefully insecure function
int get_user_input() {

// Allocate bytes to buffer //! Only 200 bytes are allocated
char buffer[200];

// Prompt user for input
printf("\n[~] Input a buffer:\n-> ");

// Read's user's input and stores it as buffer //! 400 bytes are stored in memory, this is more than the bytes allocated
int input = read(0, buffer, 400);

// Inform user the amount of bytes they supplied
printf("\n[~] You supplied %d-bytes!", input);

// Repeat the string stored in the buffer
printf("\n[+] The contents of your buffer are: %s", buffer);

return 0;

}



int main(int argc, char * argv[]) {

    //! Insecure function being called
    get_user_input();
    
    return 0;
}