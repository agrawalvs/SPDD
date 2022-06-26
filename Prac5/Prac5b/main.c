#include<stdio.h>
#include "areaperi.h"

int main(){
    float l,b,a,r,s1,s2,s3;
    printf("Enter side of square - ");
    scanf("%f" ,&a);
    printf("Area of square is %.2f\n" , AreaSquare(a));
    printf("Perimeter of square is %.2f\n" , PeriSquare(a));
    printf("___________________\n\n");
    printf("Enter height and base of Triangle  ");
    scanf("%f %f" , &l,&b);
    printf("Area of triangle is %.2f\n" , AreaTriangle(l,b));
    printf("Enter sides of triangle - ");
    scanf("%f %f %f" , &s1,&s2,&s3);
    printf("Perimeter of triangle is %.2f\n" , PeriTriangle(s1,s2,s3));
    printf("___________________\n\n");
    printf("Enter radius of circle - ");
    scanf("%f" , &r);
    printf("Area of circle is %.2f\n" , AreaCircle(r));
    printf("Perimeter of circle is %.2f\n" , PeriCircle(r));
}
