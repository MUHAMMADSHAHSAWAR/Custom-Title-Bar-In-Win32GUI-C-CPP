#include <Windows.h> // Including the windows header file for win32api Programming
using namespace std; // Defining the namespace to use the windows.h in our project.

#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "user32.lib") // Including some libraries for the windows.h header file

LPCWSTR className = (LPCWSTR)"CustomTitleBarApplication";

int WINAPI WinMain(HINSTANCE hInstance, // The existing instance value.
HINSTANCE hPrevInstance, // Previous instance of the program.
LPSTR nCMDLine, // CMD args that given as an argument in CMD.
int nCMDShow // The status of window like MAXIMIZE, MINIMIZE and VISIBLE
)
{
    // Lets Make our class

    WNDCLASSEXW windowClass = {0};
    windowClass.cbClsExtra = 0; // No extra information for the window.
    windowClass.cbSize = sizeof(windowClass); // windowClass Size
    windowClass.cbWndExtra = 0; // No extra information for the HWND.
    windowClass.hbrBackground = CreateSolidBrush(RGB(0, 0, 0)); // Background color for the window.
    windowClass.hCursor = LoadCursor(hInstance, IDC_ARROW); // Cursor of the Window.
    windowClass.hIcon = (HICON)LoadImageA(hInstance, (LPCSTR)"Icon.ico", IMAGE_ICON, 256, 256, LR_LOADFROMFILE | LR_LOADTRANSPARENT); // Loading the custom icon for the window.
    windowClass.hInstance = hInstance; // Hinstance of the window which is defined above
    windowClass.lpfnWndProc = DefWindowProc; // Window Procedure. We will change it later.
    windowClass.lpszClassName = className; // Defining the class name of the window.
    windowClass.lpszMenuName = 0; // We have no menu yet
    windowClass.style = CS_HREDRAW | CS_VREDRAW;
    
    RegisterClassExW(&windowClass);

    return 0;
}
