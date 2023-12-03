#include <windows.h>
#include <stdio.h>

int main(void) {

// Call STARTUPINFO and PROCESS_INFORMATION structures and assign the structures to si and pi variables respectively 
STARTUPINFOW si = { 0 }; // The structure variables are set to 0 to help with initialization
PROCESS_INFORMATION pi = { 0 };

    // Attempts to create the process while checking if the process was actually created
    if (!CreateProcessW(

        L"C:\\Program Files (x86)\\Microsoft\\Edge\\Application\\msedge.exe", // The name of the processs to be created is notepad with the path specified
        NULL, // Process is not on the command line
        NULL, // No special process attributes
        NULL, // No special thread attributes
        FALSE, // The process does not need to inherit handles
        ABOVE_NORMAL_PRIORITY_CLASS, // The process is started with above normal priority as a creation flag
        NULL, // No special enviroment required
        NULL, // Current directory is irrelevant
        &si, // Points to the memory address of the STARTUPINFO structure
        &pi // Points to the memory address of the PROCESS_INFORMATION structure

    )){
   
        // If the process fails to be created, display a messagebox
        MessageBoxW( 

            NULL, 
            L"Process creation failed", // The main text
             L"ERROR", // The caption
             MB_OK | MB_ICONERROR // The bottons and icon

             );

        // Print to the terminal the process failed, bringing up the last error reported
        printf("\n(-) Failed to create process, error %ld\n", GetLastError());

        // Return failure
        return 1;
        
    }

    // If all above goes as planned, print to the terminal the success followed by information about the process
    printf("\n(+) Process started!\n\t(*) PID: %ld | HANDLE: 0x%x\n\t(*) TID: %ld | HANDLE: 0x%x\n\r", pi.dwProcessId, pi.hProcess, pi.dwThreadId, pi.hThread );

    // When the process quits, print to the terminal the process is exiting
    WaitForSingleObject(pi.hProcess, INFINITE);
    printf( "\n(+) Finished! Now exiting...\n\n" );

    // Close process and thread handles
    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);

    // Return success
    return 0;
}