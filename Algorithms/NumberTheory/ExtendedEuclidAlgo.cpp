#include <bits/stdc++.h>
using namespace std;

class Triplet {
    public:
    int x;
    int y;
    int gcd;
};

// Solving linear equation "ax + by = gcd(a, b)" for x, y
// Using ax + by = (b%a)x1 + ay1
// Since gcd(a, b) = gcd(b % a, a)
Triplet gcdExtended(int a, int b) {
	// Base Case 
	if (a == 0) {
	    Triplet curr;
	    curr.x = 0;
	    curr.y = 1;
	    curr.gcd = b;
	    return curr;
	}
	
	Triplet small = gcdExtended(b % a, a);
	Triplet curr;
	
	curr.x = small.y - (b / a) * small.x;
	curr.y = small.x;
	curr.gcd = small.gcd;
	return curr;
}

int main() {
    int a, b;
    cin>>a>>b;
    Triplet ans = gcdExtended(a, b);
    cout<<ans.x<<" "<<ans.y<<" "<<ans.gcd;
	return 0;
}
