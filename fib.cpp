#include <iostream>

// Return nth fibonacci value using recursion

int fib(int n) {
  
  if(n <= 1)   //as fib(0) = 0 and fib(1) = 1
    return n;

  return fib(n - 1) + fib(n - 2);
} // end function fib 

int main() {

  std::cout << "Program to calculate the 6th Fibonacci term:" <<std::endl;
  std::cout << fib(6) << std::endl;  //calling function

  return 0;
}
