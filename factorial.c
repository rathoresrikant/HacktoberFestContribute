#include<stdio.h>
int main()
{
    int num,answer=1;
    scanf("%d",&num);
    while(num>1){
        answer*=num;
        num--;
    }
    printf("%d ",answer);
}
