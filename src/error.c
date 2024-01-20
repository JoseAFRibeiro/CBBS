#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#include <winnt.h>

void printLastError()
{
    DWORD errorCode;
    LPWSTR msgBuffer;
    errorCode = GetLastError();

    FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL, errorCode, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), &msgBuffer, 0, NULL );

    fprintf(stderr, msgBuffer);
    LocalFree(msgBuffer);
}

#endif