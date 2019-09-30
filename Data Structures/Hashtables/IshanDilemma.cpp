// https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/ishans-dilemma/
// Medium, HashMap

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, sum;
    int maxLen;
    char input[100002];
    
    cin >> t;
    while(t--) {
        cin >> n;
        scanf("%s", input);
        
        unordered_map<int,int>map;
        sum = 0; maxLen = 0;
        
        map[sum] = 0;
        for(int i = 0; i < n; i++) {
            if(input[i] == 'c') sum += 1;
            else sum -= 1;
            
            if(map.find(sum) == map.end()) {
                map[sum] = i;
            }
            else if(sum == 0) {
                maxLen = i+1;
            }
            else {
                maxLen = max(i-map[sum], maxLen);
            }
        }
        
        cout << maxLen << endl;
    }
    
    return 0;
}