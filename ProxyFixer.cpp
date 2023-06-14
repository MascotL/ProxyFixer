#include <cstdlib>  // For system() function

#ifdef _WIN32
    #include <Windows.h>  // For Windows registry functions
#endif

void disableSystemProxy() {
#ifdef _WIN32
    // Windows-specific code
    std::system("reg add \"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings\" /v ProxyEnable /t REG_DWORD /d 0 /f");
#else
    // Unix-like systems (Linux, Mac, etc.)
    std::system("unset http_proxy");
    std::system("unset https_proxy");
#endif
}

int main() {
    disableSystemProxy();
    return 0;
}
