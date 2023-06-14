#include <cstdlib>
#include <Windows.h>

void disableSystemProxy() {
    std::system("reg add \"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings\" /v ProxyEnable /t REG_DWORD /d 0 /f");
}

int main() {
    disableSystemProxy();
    return 0;
}
