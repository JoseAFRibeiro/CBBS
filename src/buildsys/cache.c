#include <stdint.h>
#include "buildsys/cache.h"
#include "cbbserr.h"

#ifdef _WIN32
#include <windows.h>
#include <fileapi.h>
#include <timezoneapi.h>

uint8_t createCacheFile(HANDLE cacheFileHandle)
{
    HANDLE fHandle;
    DWORD err;
    FILETIME  modificationTime = {0};
    FILETIME  creationTime = {0};
    SYSTEMTIME systemTimeModificationTime = {0};
    SYSTEMTIME systemTimeCreationTime = {0};
    BOOL fileResult;
    char buffer [100] = {0};

    DWORD bufferCursor = 0;

    fHandle = CreateFile("cache.cbbs", GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
    
    if(fHandle == INVALID_HANDLE_VALUE)
    {
        err = GetLastError();
        
        if(err != ERROR_FILE_EXISTS)
        {
            printLastError();
            return CACHEFILE_ERROR;
        }
        return CACHEFILE_EXISTS;
    }

    fileResult = GetFileTime(fHandle,  &creationTime, NULL, &modificationTime);
    fileResult = FileTimeToSystemTime(&modificationTime, &systemTimeModificationTime);
    fileResult = FileTimeToSystemTime(&creationTime, &systemTimeCreationTime);

    bufferCursor += wsprintf( buffer,"Creation date: %d-%d-%d | %d:%d:%d \r\n", systemTimeCreationTime.wYear, systemTimeCreationTime.wMonth, systemTimeCreationTime.wDay, systemTimeCreationTime.wHour, systemTimeCreationTime.wMinute,systemTimeCreationTime.wSecond);
    bufferCursor += wsprintf( &buffer[bufferCursor],"Modification date: %d-%d-%d | %d:%d:%d\r\n", systemTimeModificationTime.wYear, systemTimeModificationTime.wMonth, systemTimeModificationTime.wDay, systemTimeModificationTime.wHour, systemTimeModificationTime.wMinute,systemTimeModificationTime.wSecond  );

    err = WriteFile(fHandle, buffer, bufferCursor, NULL , NULL);
    if(err = FALSE)
    { 
        printLastError();
        return CACHEFILE_ERROR;
        CloseHandle(fHandle);
    }
    err = SetEndOfFile(fHandle);
    if(err = FALSE)
    { 
        printLastError();
        return CACHEFILE_ERROR;
        CloseHandle(fHandle);
    }


    return ;
}
#endif