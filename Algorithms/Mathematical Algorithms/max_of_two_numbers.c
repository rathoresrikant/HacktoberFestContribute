# include <stdio.h>

int maxNumber(int a, int b){
    int c = a-b;
    int r = (c >>31) & 0x1; 
    return (a - r*c);
    }

int main()
{
    int a = 3;
    int b = -4;
    printf("%d\n", maxNumber(a,b));
    return 0;
}
