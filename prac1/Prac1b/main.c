
#include<windows.h>
#include <stdio.h>
int _stdcall WinMain(HINSTANCE hinstance,HINSTANCE prevhinstance, LPSTR lpszcmdline, int ncmdShow){
    char buff[50];
    int a = atoi(lpszcmdline);
    int fact =1;
    for(int i=1;i<=a;i++){
      fact=fact*i;
    }
    sprintf(buff,"factorial is %d",fact);
    MessageBox(0,buff,"Title",MB_RETRYCANCEL);
    return 0;
}
