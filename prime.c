#include<stdio.h>
main()
{
    int num,i,j,C;
    scanf("%d",&num);
    for(i=2;i<num;i++)
    {
        C=0;
        for(j=2;j<=i/2;j++)
        {
            if(i%j==0)
            C++;
        }
        if(C==0)
        printf("%d ",i);
    }
    
}
