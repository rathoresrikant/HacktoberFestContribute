#include <bits/stdc++.h>

int main() {
  std::string s;
  std::cin >> s;
  std::cout << "Normal: " << s << std::endl;
  std::stack<char> st;
  for(char c : s) {
    st.push(c);
  }
  s = "";
  while(!st.empty()) {
    s += st.top();
    st.pop();
  }
  std::cout << "Reversed: " << s << std::endl;
  return 0;
}
