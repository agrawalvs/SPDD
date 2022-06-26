#include<stdio.h>

#define SUM(n,s)\
        int sum=0;\
        int temp=n;\
        while(temp>0){\
          sum+=temp%10;\
          temp/=10;}\
          s = sum;

#define REV(n,r)\
        int rev=0;\
        temp=n;\
        while(temp>0){\
          rev=10*rev+temp%10;\
          temp/=10;}\
          r = rev;


int main(){

    int n,s,r;
    printf("Enter number - ");
    scanf("%d" , &n);
    SUM(n,s);
    printf("Sum of digits of number is %d\n" ,s );
    REV(n,r);
    printf("Reverse of the number is %d\n" , r);
    if(n==r) printf("Number is palindrome\n");
    else printf("Number is not palindrome\n");

    return 0;
}
