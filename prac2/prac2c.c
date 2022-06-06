# include <windows.h>
#include <stdio.h>
#include <stdlib.h>
long _stdcall myfunc(HWND w,UINT x,UINT y, long z);
HINSTANCE hinst;
HWND hwndMain;
WNDCLASS wc;
# define ID_FILE_NEW 1
# define ID_FILE_OPEN 2
# define ID_FILE_EXIT 3
void addMenu(HWND h){
    HMENU hMenu,hParentMenu;
    hMenu = CreateMenu();

    AppendMenu(hMenu,MF_STRING,ID_FILE_NEW,"&New");
    AppendMenu(hMenu,MF_STRING,ID_FILE_OPEN,"&OPEN");
    AppendMenu(hMenu,MF_STRING,ID_FILE_EXIT,"&EXIT");
    AppendMenu(hParentMenu,MF_POPUP,hMenu,"&File");
    SetMenu(h,hParentMenu);
}
int _stdcall WinMain(HINSTANCE hInstance,HINSTANCE prevhinstance, LPSTR lpszcmdline, int nCmdShow){
    MSG msg; // for processing message
    HWND h;
    wc.lpfnWndProc = myfunc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "MainWndClass";

    RegisterClass(&wc);
    h =  CreateWindow("MainWndClass", "Window 1", WS_OVERLAPPEDWINDOW,200,10,200,200,0,0,hInstance,0);
        ShowWindow(h,SW_NORMAL);


    while(GetMessage(&msg,0,0,0)){ //2-par =handle, 3-par = lowest value, 4-par = highest value
        DispatchMessage(&msg);
    }

    return 0;
}

long _stdcall myfunc(HWND w,UINT x,UINT y, long z){
    switch(x){
        case WM_COMMAND:
            switch(y){
            case ID_FILE_NEW:
                 MessageBox(0,"New File Created","NEW FILE",MB_OK);
                break;
            case ID_FILE_OPEN:
                 MessageBox(0,"New File opened","FILE OPENED",MB_OK);
            break;
            case ID_FILE_EXIT:
                PostQuitMessage(0);
            break;
            }
        break;
        case WM_CREATE:
            addMenu(w);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(w,x,y,z);
    }
}

