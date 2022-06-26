# include <windows.h>
#include <stdio.h>
int _stdcall WinMain(HINSTANCE hinstance,HINSTANCE prevhinstance, LPSTR lpszcmdline, int nCmdShow){
    HWND h;
        int a = atoi(lpszcmdline);

        h =  CreateWindow("BUTTON", "Window 1", WS_OVERLAPPEDWINDOW,200,10,200,200,0,0,hinstance,0);
        switch(a){
            case 0 : ShowWindow(h,SW_HIDE);break;
            case 1 : ShowWindow(h,SW_NORMAL);break;
            case 2 : ShowWindow(h,SW_MINIMIZE);break;
            case 3 : ShowWindow(h,SW_MAXIMIZE);break;
        }
    MessageBox(0,"hi!","Waiting",MB_OK);
    return 0;
}
