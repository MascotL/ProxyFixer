#include <cstdlib>
#include <Windows.h>

bool disableSystemProxy() {
    HKEY hKey;
    DWORD dwValue = 0;
    LONG result = RegOpenKeyEx(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings", 0, KEY_SET_VALUE, &hKey);
    if (result == ERROR_SUCCESS) {
        result = RegSetValueEx(hKey, "ProxyEnable", 0, REG_DWORD, (BYTE*)&dwValue, sizeof(dwValue));
        RegCloseKey(hKey);
        if (result != ERROR_SUCCESS) return false;
    } else return false;
    return true;
}

int main() {
    disableSystemProxy();
    return 0;
}