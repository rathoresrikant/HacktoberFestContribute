// C++ implementation to check if a number has bits in alternate pattern 
#include <bits/stdc++.h> 
  
using namespace std; 
  
// function to check if all the bits are set or not in the binary representation of 'n' 
bool allBitsAreSet(unsigned int n) 
{ 
    // if true, then all bits are set 
    if (((n + 1) & n) == 0) 
        return true; 
      
    // else all bits are not set 
    return false; 
} 
  
// function to check if a number has bits in alternate pattern 
bool bitsAreInAltOrder(unsigned int n) 
{ 
    unsigned int num = n ^ (n >> 1); 
      
    // to check if all bits are set  in 'num' 
    return allBitsAreSet(num);         
} 
  
 
int main() 
{ 
  	int n;
  	cout<<"Enter value of n"<<endl;
  	cin>>n;
      
    if (bitsAreInAltOrder(n)) 
        cout << "Yes"<<endl; 
    else
        cout << "No"<<endl; 
          
    return 0;         
}  
