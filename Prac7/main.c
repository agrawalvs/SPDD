#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<direct.h>
#include<process.h>
#include<ctype.h>
#include<windows.h>
void gotoxy(int x, int y)
{
static HANDLE h = NULL;
if(!h)
h = GetStdHandle(STD_OUTPUT_HANDLE);
COORD c = { x, y };
SetConsoleCursorPosition(h,c);
}
int main()
{
int x,y;
union REGS regs;
int c;
clrscr();
do{
printf("1.Setting Cursor size\n2.Scroll the Window Down\n3.Positioning
the Cursor\n4.Reading The Cursor Position\n5.Exit\n");
printf("\nEnter your choice:\n");
scanf("%d",&c);
switch(c)
{
case 1:
printf("Enter the Starting line of the Cursor[0-4):\n");
scanf("%d",&x);
printf("Enter the Ending line of the Cursor:\n");
scanf("%d",&y);
gotoxy(40,12);
regs.h.ah=1;
regs.h.ch=x;
regs.h.cl=y;
int86(0x10,&regs, &regs);
getch();
break;
case 2:
regs.h.ah=7;
regs.h.al=5;
regs.h.bh=8;
regs.h.ch=0;
regs.h.cl=0;
regs.h.dh=50;
regs.h.dl=50;
int86 (0x10,&regs, &regs);
break;

case 3:
printf("Enter the X-Position:\n");
scanf("%d",&x);
printf("Enter the Y-Position:\n");
scanf("%d",&y);
regs.h.ah=2;
regs.h.bh=0;
regs.h.dh=y;
regs.h.dl=x;
int86(0x10,&regs,&regs);
break;
case 4:
regs.h.ah=3;
regs.h.bh=9;
regs.h.dh=8;
regs.h.dl=27;
int86(0x10,&regs,&regs);
printf("The Row Position of Cursor on Selected Page:%d\n
",regs.h.ch);
printf("The Column Position of Cursor on Selected
Page:%d\n",regs.h.cl);
break;
case 5:
printf("Exiting.. \n");
exit(0);
}
}while(c!=5);
return 0;
}


