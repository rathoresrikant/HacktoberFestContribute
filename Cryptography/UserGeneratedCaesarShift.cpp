// This is an update to the previous caesar.cpp file from user
// AnkitGuleria to add a user generated text and shift number


#include <iostream> 
using namespace std; 
  
string encrypt(string text, int s) 
{ 
    string result = ""; 
  
    for (int i=0;i<text.length();i++) 
    { 
        if (isupper(text[i])) 
            result += char(int(text[i]+s-65)%26 +65); 
  
    else
        result += char(int(text[i]+s-97)%26 +97); 
    } 
  
    return result; 
} 
  
// Driver program 
int main() 
{ 
    string defaultText="ATTACKATONCE"; // Left as the default text
    string text = "nothingtoSeeHere"; 
    int defaultShift = 4; // Left as the default shift value
    int s = 0;
    cout << "Text to encrypt? : ";
    cin >> text;
    if (!cin)
    {
      text = defaultText;
    } 
    cout << "\nShift desired? : ";
    cin >> s;
    if (!cin)
    {
      s = defaultShift;
    } 
    cout << "\nHere is your encrypted text: " << encrypt(text, s) << endl; 
    return 0; 
} 

