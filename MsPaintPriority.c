#include <windows.h>
#include <stdio.h>




int main(void) {

    /* Using this as a guide reference for the Windows CreateProcess Function
    BOOL CreateProcessW(
    [in, optional]      LPCWSTR               lpApplicationName,
    [in, out, optional] LPWSTR                lpCommandLine,
    [in, optional]      LPSECURITY_ATTRIBUTES lpProcessAttributes,
    [in, optional]      LPSECURITY_ATTRIBUTES lpThreadAttributes,
    [in]                BOOL                  bInheritHandles,
    [in]                DWORD                 dwCreationFlags,
    [in, optional]      LPVOID                lpEnvironment,
    [in, optional]      LPCWSTR               lpCurrentDirectory,
    [in]                LPSTARTUPINFOW        lpStartupInfo,
    [out]               LPPROCESS_INFORMATION lpProcessInformation
    );
    */

    STARTUPINFOW si = {0};
    PROCESS_INFORMATION pi = {0};



    
    void highPriorityPaint() {
        if (!CreateProcessW(
            L"C:\\Windows\\System32\\mspaint.exe",
            NULL,
            NULL,
            NULL,
            FALSE,
            HIGH_PRIORITY_CLASS,
            NULL,
            NULL,
            &si,   // Don't have to worry about these for the time being
            &pi    //
        ))
        {

        printf("(-) failed to create process, error: %ld", GetLastError());
        return 1;

        }   
    }


    
    void lowPriorityPaint() {
        if (!CreateProcessW(
            L"C:\\Windows\\System32\\mspaint.exe",
            NULL,
            NULL,
            NULL,
            FALSE,
            BELOW_NORMAL_PRIORITY_CLASS,
            NULL,
            NULL,
            &si,
            &pi
        ))
        {

        printf("(-) failed to create process, error: %ld", GetLastError());
        return 1;

        }   
    }   


    //Can call the program with either high or low priority with these 2 funcitons I made, see the 6th parameter for reference or 'dwCreationFlags'
    
    highPriorityPaint();
    //lowPriorityPaint();    

    return 0;
}

