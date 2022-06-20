#include <windows.h>
#include <stdio.h>

long _stdcall myfunc (HWND, UINT, UINT, long);
WNDCLASS a;
int flag = 0, x1, y1;

int _stdcall WinMain(HINSTANCE i, HINSTANCE j, LPSTR lpszCmdline, int nCmdShow){
    HWND h;
    MSG m;

    a.hInstance = i;
    a.lpszClassName= "my";
    a.lpfnWndProc = myfunc;
    a.hbrBackground = (HBRUSH)GetStockObject (WHITE_BRUSH);
    RegisterClassA(&a);

    h = CreateWindow ("my", "Title", WS_OVERLAPPEDWINDOW,10, 10, 150, 100, 0, 0, i, 0);

    ShowWindow (h, 3);
    while (GetMessage (&m, 0, 0, 0))
        DispatchMessage (&m);
    return 0;
}

long _stdcall myfunc (HWND w, UINT x, UINT y, long z){
    HDC d;
    switch (x){
        case WM_LBUTTONDOWN:
            if ( flag == 0){
                x1 = LOWORD (z);
                y1 = HIWORD (z);
                flag = 1;
            }
            else{
                d = GetDC (w);
                MoveToEx (d, x1, y1, 0);
                LineTo (d, LOWORD(z), HIWORD (z));
                ReleaseDC (w,d);
                flag = 0;
            }
            break;
        case WM_DESTROY:
            PostQuitMessage (0);
            break;

        default:
            return DefWindowProc (w, x, y, z);
    }
    return OL;
}

