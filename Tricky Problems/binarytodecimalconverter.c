// binary to decimal converter
// generalize program
#include <stdio.h>
#include <math.h>
int convertBinaryToDecimal(long long n);

int main()
{
    long long t;
    printf("Enter a binary number: ");
    scanf("%lld", &t);
    printf("%lld in binary = %d in decimal", t, convertBinaryToDecimal(t));
    return 0;
}

int convertBinaryToDecimal(long long t)
{
    int decimalNumber = 0, i = 0, r;
    while (t!=0)
    {
        r = t%10;
        t /= 10;
        decimalNumber += r*pow(2,i);
        ++i;
    }
    return decimalNumber;
}

