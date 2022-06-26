/*
Study of graphics under windows

1.Write a program to display hello window in user defined window
2.Write a program to draw different shapes using pen
3.Write a program to draw lines using different type of pen
4.Write a program for free hand drawing.

*/

#include <windows.h>
#include "helper.h"
#include<graphics.h>

void OnPaint(HWND);
void OnDestroy(HWND);

int _stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdline, int nCmdShow)
{
    MSG m;

    InitInstance(hInstance, nCmdShow, "Text");

    while(GetMessage(&m, NULL, 0, 0))
        DispatchMessage(&m);

    return 0;
}

LRESULT CALLBACK WndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM IParam)
{
    switch(message)
    {
       case WM_DESTROY:
           OnDestroy(hWnd);
           break;
       case WM_PAINT:
           OnPaint(hWnd);
           break;
       default:
        return DefWindowProc(hWnd, message, wParam, IParam);

    }
    return 0;
}

void OnDestroy(HWND hWnd)
{
    PostQuitMessage(0);
}

void OnPaint(HWND hWnd)
{
    HDC hdc;
    PAINTSTRUCT ps;
    HFONT hfont;
    LOGFONT f = {0};
    HGDIOBJ holdfont;
    char *fonts[]={"Arial","Times New Roman","Comic Sans MS"};
    int i;
    hdc = BeginPaint(hWnd, &ps);

    for(i=0;i<3;i++)
    {
        strcpy(f.lfFaceName, fonts[i]);
        f.lfHeight = 40*(i+1);
        f.lfItalic = 1;

        hfont = CreateFontIndirect(&f);
        holdfont = SelectObject(hdc, hfont);

        SetTextColor(hdc, RGB(0,0,255));

        TextOut(hdc, 10, 70*i,"Hello Windows",13);

        SelectObject(hdc, holdfont);
        DeleteObject(hfont);
    }
        EndPaint(hWnd,&ps);
}

