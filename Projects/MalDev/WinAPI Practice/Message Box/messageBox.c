#include <windows.h>

int main(void) {

    MessageBoxW(
        NULL,
        L"Did it display??",
        L"Hello, world!",
        MB_YESNO | MB_ICONQUESTION
    );

    return 0;
}