#include <stdint.h>
#include <buildsys/buildfile.h>

#ifdef _WIN32

#include <windows.h>
#include <fileapi.h>

uint8_t checkChanges()
{
    HANDLE fHandle;
    LPFILETIME modificationTime;
    BOOL getFileTimeResult;

    fHandle = CreateFile("build.cd", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    
    if(fHandle == INVALID_HANDLE_VALUE) return CBBS_FILE_ERROR;
    
    getFileTimeResult = GetFileTime(fHandle, NULL, NULL, modificationTime);

}
#endif

#ifdef _LINUX
uint8_t checkChanges()
{
    
}
#endif