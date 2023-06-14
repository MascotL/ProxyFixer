#include <cstdlib>
#include <Windows.h> 


void disableSystemProxy() {

    // Hide console window
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_HIDE);
    // ShowWindow(hWnd, SW_SHOW);
    std::system("reg add \"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings\" /v ProxyEnable /t REG_DWORD /d 0 /f");
}

int main() {
    disableSystemProxy();
    return 0;
}
