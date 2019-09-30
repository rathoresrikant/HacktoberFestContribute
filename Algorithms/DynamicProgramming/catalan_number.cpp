
#include <iostream> 
using namespace std; 
  
// A dynamic programming based function to find nth 
// Catalan number 
unsigned long int catalan(unsigned int n) 
{ 
    unsigned long int catlnno[n+1]; 
    catlnno[0] = catlnno[1] = 1; 
    for (int i=2; i<=n; i++) 
    { 
        catlnno[i] = 0; 
        for (int j=0; j<i; j++) 
            {
              catlnno[i] += catlnno[j] * catlnno[i-j-1]; 
             }
    } 

    return catlnno[n]; //Return nth Catalan No
} 
  
int main() 
{ 
    int n=10; 
        cout << catalan(n) << " "; 
    return 0; 
} 

