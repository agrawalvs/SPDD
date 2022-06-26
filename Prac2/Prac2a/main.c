# include <windows.h>
#include <stdio.h>
int _stdcall WinMain(HINSTANCE hinstance,HINSTANCE prevhinstance, LPSTR lpszcmdline, int nCmdShow){
    HWND h,h1,h2,h3,h4,h5,h6;

        h =  CreateWindow("BUTTON", "Window 1", WS_OVERLAPPEDWINDOW,200,10,200,200,0,0,hinstance,0);
        ShowWindow(h,nCmdShow);

        h1 =  CreateWindow("BUTTON", "Window 2", WS_BORDER,300,10,200,200,0,0,hinstance,0);
        ShowWindow(h1,nCmdShow);

        h2 =  CreateWindow("BUTTON", "Window 3", WS_CAPTION,400,10,200,200,0,0,hinstance,0);
        ShowWindow(h2,nCmdShow);

        h3 =  CreateWindow("BUTTON", "Window 4", WS_HSCROLL,50*10,10,200,200,0,0,hinstance,0);
        ShowWindow(h3,nCmdShow);

        h4 =  CreateWindow("BUTTON", "Window 5", WS_SYSMENU,60*10,10,200,200,0,0,hinstance,0);
        ShowWindow(h4,nCmdShow);

        h5=  CreateWindow("BUTTON", "Window 6", WS_VSCROLL,70*10,10,200,200,0,0,hinstance,0);
        ShowWindow(h5,nCmdShow);

        h6=  CreateWindow("BUTTON", "Window 7", WS_MINIMIZE,70*10,10,200,200,0,0,hinstance,0);
        ShowWindow(h6,nCmdShow);
    MessageBox(0,"hi!","Waiting",MB_OK);
    return 0;
}
