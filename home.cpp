#include "home.h"

#include <Windows.h>

using namespace alexcrevork;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew home);
    return 0;
}