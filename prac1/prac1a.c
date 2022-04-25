#include<windows.h>
#include <stdio.h>
int _stdcall WinMain(HINSTANCE hinstance,HINSTANCE prevhinstance, LPSTR lpszcmdline, int ncmdShow){
    char buff[50];
    sprintf(buff,"hinstance is %d",hinstance);
    MessageBox(0,buff,"Title",MB_RETRYCANCEL);
    return 0;
}
