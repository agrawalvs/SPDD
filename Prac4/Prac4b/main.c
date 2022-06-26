#include<windows.h>

long _stdcall myfunc(HWND,UINT,UINT,long);
WNDCLASS a;

int _stdcall WinMain(HINSTANCE i, HINSTANCE j, char *k,int l)
{
    HWND h;
    MSG m;

    a.hInstance = i;
    a.lpszClassName = "My";
    a.lpfnWndProc = myfunc;
    a.hbrBackground = GetStockObject(WHITE_BRUSH);

    RegisterClass(&a);
    h = CreateWindow("My","Title",WS_OVERLAPPEDWINDOW,10,10,150,100,0,0,i,0);
    ShowWindow(h,3);
    while(GetMessage(&m,0,0,0))
        DispatchMessage(&m);
    return 0;
}

long _stdcall myfunc(HWND w,UINT x,UINT y,long z)
{
    HDC d;
    int x1,y1;
    switch(x)
    {
    case WM_LBUTTONDOWN:

            x1 = LOWORD(z);
            y1 = HIWORD(z);
            d = GetDC(w);
            MoveToEx(d,x1,y1,0);
            TextOut(d,x1,y1,"Hello",6);
            ReleaseDC(w,&d);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(w,x,y,z);
    }
    return 0L;
}







