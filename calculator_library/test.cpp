#include "calculator.h"
#include<iostream>
int main()
{
    float firstNumber,secondNumber;
    std::cout << "Enter two numbers to addition";
    std::cin >> firstNumber >> secondNumber;
    float x;
    x=addition(firstNumber,secondNumber);

    std::cout << "Sum :" << x << std::endl;
    std::cout << "Subtraction :" << subtract(firstNumber,secondNumber) << std::endl;
    std::cout << "Multiplication :" << multiplication(firstNumber,secondNumber) << std::endl;
    std::cout << "Division :" << divide(firstNumber,secondNumber) << std::endl;
    std::cout << "Remainder :" << remainder(firstNumber,secondNumber) << std::endl;


    return 0;

    
}
