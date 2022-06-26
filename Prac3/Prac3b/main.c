#include <stdlib.h>
#include<windows.h>
#include "helper.h"
void OnPaint(HWND);
void OnDestroy(HWND);
int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR
lpszCmdline, int nCmdShow)
{
 MSG m;
 InitInstance(hInstance, nCmdShow, "Text");
 while(GetMessage (&m, NULL, 0,0))
 DispatchMessage(&m);
 return 0;
}
LRESULT CALLBACK WndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM
lParam){
 switch(message){
 case WM_DESTROY:
 OnDestroy(hWnd);
 break;
 case WM_PAINT:
 OnPaint(hWnd);
 break;
 default:
 return DefWindowProc(hWnd, message, wParam, lParam);
 }
 return 0;
}
void OnDestroy(HWND hWnd){
 PostQuitMessage(0);
}
void OnPaint(HWND hWnd){
 HDC hdc;
 PAINTSTRUCT ps;
 HBRUSH hbr;
 HGDIOBJ holdbr;
 POINT pt[5] = {400, 300, 500, 300, 300, 350, 600, 300, 320, 250};
 hdc = BeginPaint(hWnd, &ps);
 hbr = CreateSolidBrush(RGB(0,0,0));
 holdbr = SelectObject(hdc, hbr);
 MoveToEx(hdc, 10, 10, NULL);
 LineTo(hdc, 200, 10);
  Ellipse(hdc, 10, 240, 300, 340);

 RoundRect(hdc, 10, 120, 200, 220, 20, 20);
  Rectangle(hdc, 10, 20, 200, 100);

 Polygon(hdc, pt, 5);
 SelectObject(hdc, holdbr);
 DeleteObject(hbr);
 EndPaint(hWnd, &ps);
}
