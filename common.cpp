// HacktoberFestContribute; 
// HacktoberFest 2018

#include <iostream>
#include <algorithm>
#include <string>

// function common prints the common characters of two strings in alphabetical order.
void common(const std::string& str1, const std::string& str2)
{
  std::string common = "";
  int len1 = str1.length();
  int len2 = str2.length();

  for(int i = 0; i < len1; ++i) {
    for(int j = 0; j < len2; ++j) {
      // concatenate common character 
      if(!isspace(str1[i]) && str1[i] == str2[j]) {
        common = common + str1[i];
      }
    }
  }

  // sort common characters alphabetically
  std::sort(common.begin(), common.end());
  // remove duplicate characters 
  common.erase(std::unique(common.begin(), common.end()), common.end());
  // print common characters 
  for(const char& c : common)
    std::cout << c << ' ';
}

int main()
{
  std::string first = "HacktoberFest Contribution";
  std::string second = "October 2018";
  common(first, second);
}
