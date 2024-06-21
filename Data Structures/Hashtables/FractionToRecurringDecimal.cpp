class Solution {
public:
    string fractionToDecimal(int n, int d) {
       string s;
        int i = 0;
        if(!n) return "0";
        if(n<0 ^ d<0) s += "-";
        long numerator = fabs(long(n)), denominator = fabs(long(d));
        s += to_string(numerator/denominator);
        numerator %= denominator;
        if(numerator) s += ".";
        unordered_map<int, int> pos_map;
        i = s.length()-1;
        while(numerator)
        {
            if(pos_map.count(numerator))
            {
                s.insert(pos_map[numerator], "(");
                s += ")";
                break;
            }
            pos_map[numerator] = ++i;
            numerator *= 10;
            s += to_string(numerator/denominator);
            numerator %= denominator;
        }
        return s;
    }
};
