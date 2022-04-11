# include <windows.h>

int WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
    HWND h[5];
    for(int i=0;i<=4;i++)
    {
        h[i] =  CreateWindow("BUTTON", "Hit Me", WS_OVERLAPPEDWINDOW,i*10*10,i*10*10,200,200,0,0,hInstance,0);
        ShowWindow(h[i],nCmdShow);

    }
    MessageBox(0,"hi!","Waiting",MB_OK);
    return 0;
}
