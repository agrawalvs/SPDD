# include <windows.h>

int WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow) // in .c we can use int_stdcall WinMain()
{
    MessageBox(0,"hello","Title",MB_OK);
    return 0;
}
