#include <windows.h>
#include <stdio.h>

int main() {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Path to mspaint.exe (Windows automatically locates it if in system path)
    LPCSTR program = "mspaint.exe";

    // Create child process
    if (!CreateProcess(
            NULL,        // Application name
            (LPSTR)program,   // Command line
            NULL,        // Process security
            NULL,        // Thread security
            FALSE,       // Inherit handles
            0,           // Creation flags
            NULL,        // Environment
            NULL,        // Current directory
            &si,         // Startup info
            &pi)) {      // Process info
        printf("Failed to start mspaint.exe. Error: %lu\n", GetLastError());
        return 1;
    }

    printf("Successfully created child process running mspaint.exe\n");
    printf("Child PID: %lu\n", pi.dwProcessId);

    // Optionally wait for paint to close
    WaitForSingleObject(pi.hProcess, INFINITE);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
