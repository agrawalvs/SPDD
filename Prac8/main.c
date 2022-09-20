#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <process.h>
int initmouse();
void showmouseptr();
void getmousepos(int *button, int *x, int *y);
union REGS i, O;
main()
{
int status,
gd = DETECT, gm, button, x, y, tempx, tempy;
char array[50];
int c;
do
{
printf("1.Check if mouse Support is Available or
not\n2.Display mouse pointer in graphics mode\n3.Determine which
mouse button is cilcked\n4.Current position of mouse
pointer\n5.Exit\n");
printf("Enter your Choice:\n");

scanf("%d", &c);
switch (c){
case 1:
status = initmouse();
if (status == 0)
printf("Mouse Support not Available.\n");
else
printf("Mouse Support is Available.\n");
getch();
break;
case 2;
initgraph(&gd, &gm, "C:\\TC\\BGI");
status = initmouse();
if (status == 0)
printf("Mouse support not Available.\n");
else
showmouseptr();
getch();
closegraph();
break;
case 3:
initgraph(&gd, &gm, "..\\BGI");
settextstyle(DEFAULT_FONT, 0, 2);
status = initmouse();
if (status == 0)
printf("Mouse support not Available.\n");
else
{
showmouseptr();
getmousepos(&button, &x, &y);
while (!kbhit())
{
getmousepos(&button, &x, &y);
if (button == 1)
{
button = -1;
cleardevice();
cleardevice();
sprintf(array, "Left Button Clicked x = %
d y = % d", x, y);
outtext(array);
}
else if (button == 2)
{
button = -1;
cleardevice();
sprintf(array, "Right Button Clicked x =
% d y = % d", x, y);
outtext(array);
}
}
}
getch();
closegraph();
break;
case 4:
initgraph(&gd, &gm, "..\\BGI");
settextstyle(DEFAULT_FONT, 0, 2);
status = initmouse();
if (status == 0)
printf("Mouse support not Available.\n");
else
{
showmouseptr();
getmousepos(&button, &x, &y);
tempx = x;
tempy = y;
while (!kbhit())
{
getmousepos(&button, &x, &y);
if (x == tempx && y == tempy)
{
}
else
{
cleardevice();
sprintf(array, "X=%d, Y=%d", x, y);
outtext(array);
tempx = x;
tempy = y;
}
}

}
getch();
closegraph();
break;
case 5:
exit(0);
}
}while (c !=5);
return 0;
}
int initmouse()
{
i.x.ax = 0;
int86(0X33, &i, &O);
return (O.x.ax);
}
void showmouseptr()
{
i.x.ax = 1;
int86(0X33, &i, &O);
}
void getmousepos(int *button, int *x, int *y)
{
i.x.ax = 3;
int86(0X33, &i, &O);
*button = O.x.bx;
*button = O.x.bx;
*x = O.x.cx;
*y = O.x.dx;
}
