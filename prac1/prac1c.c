#include<windows.h>
#include <stdio.h>
#include<ctype.h>
int _stdcall WinMain(HINSTANCE hinstance,HINSTANCE prevhinstance, LPSTR lpszcmdline, int ncmdShow){
    char words[50];
    int count = 0;
    int digit =0;
    int vovel =0;
    for (int i = 0;lpszcmdline[i] != '\0';i++)
    {
        if (lpszcmdline[i] == ' '){
            count++;
        }
        if(lpszcmdline[i] == 'a' || lpszcmdline[i] == 'e' || lpszcmdline[i] == 'i' || lpszcmdline[i] == 'o' || lpszcmdline[i] == 'u'){
            vovel++;
        }
        if(isdigit(lpszcmdline[i])){
            digit++;
        }
    }
    sprintf(words,"%s \nno of words are %d \nno of vovels are %d\nno of digits are %d",lpszcmdline,count,vovel,digit);
    MessageBox(0,words,"Title",MB_RETRYCANCEL);
    return 0;
}
