#include "calculator.h"


float addition(float firstNumber,float secondNumber)
{
    return firstNumber+secondNumber;
}
float subtract(float firstNumber,float secondNumber)
{
    return firstNumber-secondNumber;
}
float multiplication(float firstNumber,float secondNumber)
{
    return firstNumber*secondNumber;
}
float divide(float divident,float divisor)
{
    return divident/divisor;
}
float remainder(float divident,float divisor)
{
    int firstNumberNew=(int)divident;
    int secondNumberNew=(int)divisor;
    return firstNumberNew%secondNumberNew;
    
}
