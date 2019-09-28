#include <iostream>

using namespace std;

//Function name: getRaiseAndAdd
//Purpose: Calculate each digit cubed and the sum of the results.
//We are sending in the current number from the loop starting at 100 and
//counting one by one to 999.
//Parameters: &numberInput
//Return value: Result of adding 3 numbers
int getRaiseAndAdd(int &numberInput)
{
int firstNumber, secondNumber, thirdNumber;
int remainder;
int sum;
int firstPower, secondPower, thirdPower;

firstNumber = numberInput / 100;
remainder = numberInput % 100;
secondNumber = remainder / 10;
thirdNumber = remainder % 10;

firstPower = firstNumber * firstNumber * firstNumber;
secondPower = secondNumber *secondNumber * secondNumber;
thirdPower = thirdNumber * thirdNumber * thirdNumber;

return sum = firstPower + secondPower + thirdPower;
}

int main()
{
int answer;
int originalNumber;

for(int i = 100; i < 1000; i++)
originalNumber = i;

answer = getRaiseAndAdd(i);
        {
        //Function name: is_Armstrong
        //Purpose: finding the Armstrong numbers
        //Parameters: answer
        //Return value: 0
        bool is_Armstrong (int answer);
        if(answer == originalNumber);
                {
                cout << "found an Armstrong number " << originalNumber << endl;
                }
        }

return 0;
}
