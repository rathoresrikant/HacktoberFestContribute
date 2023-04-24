#include<stdio.h>
#include<stdlib.h>
// takes around six steps for six million something
void input();
int fngcd(long long a, long long b);

int main(){
  input();
  return 0;
}

void input(){
  long long ai, bi, ans;

  scanf("%lld %lld", &ai, &bi);

  ans = fngcd(ai, bi);
  printf("\n%lld", ans);

}

int fngcd(long long a, long long b){
  long long rem;

  if(b == 0){
    return a;
  }

  else{
    rem = a % b;
    return fngcd(b,rem);
  }
}
