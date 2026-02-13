#include <windows.h>

#define HOTKEY_NEXT 1
#define HOTKEY_PREV 2

void SendMediaKey(DWORD key) {
    INPUT input = {0};
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = key;
    input.ki.dwFlags = KEYEVENTF_EXTENDEDKEY;
    SendInput(1, &input, sizeof(INPUT));
    
    input.ki.dwFlags = KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(INPUT));
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Register hotkeys: Ctrl+Right and Ctrl+Left
    RegisterHotKey(NULL, HOTKEY_NEXT, MOD_CONTROL, VK_RIGHT);
    RegisterHotKey(NULL, HOTKEY_PREV, MOD_CONTROL, VK_LEFT);
    
    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0)) {
        if (msg.message == WM_HOTKEY) {
            if (msg.wParam == HOTKEY_NEXT) {
                SendMediaKey(VK_MEDIA_NEXT_TRACK);
            } else if (msg.wParam == HOTKEY_PREV) {
                SendMediaKey(VK_MEDIA_PREV_TRACK);
            }
        }
    }
    
    return 0;
}