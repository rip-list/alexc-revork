#include "home.h"

#include <Windows.h>

using namespace alexcrevork;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    alexcrevork::Application::EnableVisualStyles();
    alexcrevork::Application::SetCompatibleTextRenderingDefault(false);
    alexcrevork::Application::Run(gcnew home);
    return 0;
}