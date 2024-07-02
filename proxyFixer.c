#include <windows.h>
#include <stdio.h>

#define REGISTRY_PATH TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings")
#define PROXY_ENABLE TEXT("ProxyEnable")

void proxyFixer() {
    HKEY hKey;
    DWORD proxyEnableValue;
    DWORD dataSize = sizeof(proxyEnableValue);
    LONG result;

    result = RegOpenKeyEx(HKEY_CURRENT_USER, REGISTRY_PATH, 0, KEY_READ | KEY_WRITE, &hKey);
    if (result != ERROR_SUCCESS) return;

    result = RegQueryValueEx(hKey, PROXY_ENABLE, NULL, NULL, (LPBYTE)&proxyEnableValue, &dataSize);
    if (result != ERROR_SUCCESS) return;

    if (proxyEnableValue == 1) {
        proxyEnableValue = 0;
        result = RegSetValueEx(hKey, PROXY_ENABLE, 0, REG_DWORD, (const BYTE*)&proxyEnableValue, dataSize);
    }

    RegCloseKey(hKey);
}

int main() {
    proxyFixer();
    return 0;
}
