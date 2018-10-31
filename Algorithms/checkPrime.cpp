/*
*     Checks if a number is prime or not
*
*     Runs in O(sqrt(n)) time!
*
*     Created 31/10/18
*/

#include <iostream>
#include <math.h>

int main(){
  unsigned long long n, sqrtn;
  std::cout << "Enter a Number: ";
  std::cin >> n;

  sqrtn = sqrt(n);

  for(unsigned long long i = 2; i <= sqrtn; i++){

    if(n % i == 0){
      std::cout << n << " is Not Prime!" << std::endl;
      return 0;
    }

  }

  std::cout << n << " is Prime!" << std::endl;
  return 1;

}