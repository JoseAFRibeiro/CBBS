#include <stdint.h>
#include <windows.h>
#include <direct.h>

int main()
{
    wchar_t buffer[256];
    _wgetcwd(buffer, 256);
    createCacheFile();
    return 0;
}

/*uint8_t buildsysmain()
{
    //Read the recipee file and execute the commands
}*/