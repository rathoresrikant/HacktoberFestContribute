#define l(x) (x>=97&&x<=122)
#define u(x) (x>=65&&x<=90)
char *swap_case(char *s){for(char*p=s;*p;p++)*p=(l(*p)?*p-32:(u(*p)?*p+32:*p));return s;}
