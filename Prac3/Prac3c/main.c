#include <windows.h>
#include "helper.h"

void OnPaint(HWND);
void OnDestroy(HWND);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdline, int nCmdShow)
{
    MSG m;

    InitInstance(hInstance, nCmdShow, "Shapes");

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
/*
void OnPaint ( HWND hWnd ){
    HDC hdc ;
    PAINTSTRUCT ps ;
    HBRUSH hbr;
    HGDIOBJ holdbr ;

    POINT pt[5] = { 250, 150, 250, 300, 300, 350, 400, 300, 320, 190 } ;
    hdc = BeginPaint ( hWnd, &ps ) ;
    hbr = CreateSolidBrush ( RGB ( 255, 0, 0 ) ) ;

    holdbr = SelectObject ( hdc, hbr ) ;
    MoveToEx( hdc, 10, 10, NULL ) ;
    LineTo ( hdc, 200, 10 ) ;
    Rectangle ( hdc, 10, 20, 200, 100 ) ;

    RoundRect ( hdc, 10, 120, 200, 220, 20, 20 ) ;
    Ellipse ( hdc, 10, 240, 200, 340 ) ;
    Pie ( hdc, 250, 10, 350, 110, 350, 110, 350, 10 ) ;

    Polygon ( hdc, pt, 5 ) ;
    SelectObject ( hdc, holdbr ) ;
    DeleteObject ( hbr ) ;
    EndPaint ( hWnd, &ps ) ;
}*/

void OnPaint ( HWND hWnd )
{
    HDC hdc ;
    PAINTSTRUCT ps ;
    HPEN hpen ;
    HGDIOBJ holdpen ;

    hdc = BeginPaint ( hWnd, &ps ) ;
    hpen = CreatePen ( PS_DASH, 1, RGB ( 255, 0, 0 ) ) ;
    holdpen = SelectObject ( hdc, hpen ) ;
    MoveToEx ( hdc, 10, 10, NULL ) ;

    LineTo ( hdc, 500, 10 ) ;
    SelectObject ( hdc, holdpen ) ;
    DeleteObject ( hpen ) ;
    hpen = CreatePen ( PS_DOT, 1, RGB ( 255, 0, 0 ) ) ;
    holdpen = SelectObject ( hdc, hpen ) ;

    MoveToEx ( hdc, 10, 60, NULL ) ;
    LineTo ( hdc, 500, 60 ) ;
    SelectObject ( hdc, holdpen ) ;
    DeleteObject ( hpen ) ;


    hpen = CreatePen ( PS_DASHDOT, 1, RGB ( 255, 0, 0 ) ) ;
    holdpen = SelectObject ( hdc, hpen ) ;
    MoveToEx ( hdc, 10, 110, NULL ) ;
    LineTo ( hdc, 500, 110 ) ;

    SelectObject ( hdc, holdpen ) ;
    DeleteObject ( hpen ) ;
    hpen = CreatePen ( PS_DASHDOTDOT, 1, RGB ( 255, 0, 0 ) ) ;
    holdpen = SelectObject ( hdc, hpen ) ;
    MoveToEx ( hdc, 10, 160, NULL ) ;

    LineTo ( hdc, 500, 160 ) ;
    SelectObject ( hdc, holdpen ) ;
    DeleteObject ( hpen ) ;
    hpen = CreatePen ( PS_SOLID, 10, RGB ( 255, 0, 0 ) ) ;
    holdpen = SelectObject ( hdc, hpen ) ;

    MoveToEx ( hdc, 10, 210, NULL ) ;
    LineTo ( hdc, 500, 210 ) ;
    SelectObject ( hdc, holdpen ) ;
    DeleteObject ( hpen ) ;
    EndPaint ( hWnd, &ps ) ;
}
