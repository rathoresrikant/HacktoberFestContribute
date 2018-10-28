#include<stdio.h>
main()
{
    int m=300,*mp;
    float fx=300.600006,*fxp;
    char cht='z',*chtp;
    mp=&m;fxp=&fx;chtp=&cht;
    printf("\nPointer : Demonstrate the use of & and * operator :\n");
    printf("---------------------------------------------------\n");
    printf("m = %d\nfx = %f\ncht = %c\n",m,fx,cht);
    printf("\nUsing & operator :\n");
    printf("------------------\n");
    printf("address of m = %u\naddress of fx = %u\naddress of cht = %u\n",&m,&fx,&cht);
    printf("\nusing & and * operator :\n");
    printf("------------------------\n");
    printf("value at address of m  = %d\nvalue at address of fx = %f\nvalue at address of m  = %c\n",*(&m),*(&fx),*(&cht));
    printf("\nUsing only Pointer variable\n");
    printf("---------------------------\n");
    printf("Address of m = %u\nAddress of fx = %u\nAddress of cht = %u\n",mp,fxp,chtp);
    printf("\nUsing only pointer Operator\n");
    printf("---------------------------\n");
    printf("value at address of m  = %d\nvalue at address of fx = %f\nvalue at address of m  = %c\n",*mp,*fxp,*chtp);
    printf("\n                      Program By Dev\n\n");
}
