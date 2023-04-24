
/*
** Name :- Anshu Kumari
** Institute :- IERT, Allahabad
*/

/* Replacing digit at position 'k' in a given number 'n' with value 'x'. */

 #include<iostream>
 using namespace std;
 
  int i,j;
    
     int main()
     {
         int t;
          cin>>t;
          
           while(t--)
           {
               int n; // Given number n
                 cin>>n;
                 
                 int k,x; // k is position of digit to be removed with value x
                  cin>>k>>x;
                 
                 string s = to_string(n); // Converting n to string s
                 
                   for(i=0;i<s.length();i++)
                   {
                       if(i==k-1) // printing value x for position k
                         cout<<x;
                         
                         else
                           cout<<s[i];
                   }
                   
                   cout<<endl;
           }
     }
/* Time Complexity :- O(n) */
