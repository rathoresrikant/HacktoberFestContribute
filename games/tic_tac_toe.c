#include <stdio.h>

int main(void)
{

	int ar[3][3]={9,9,9,9,9,9,9,9,9};
	int a,b,input;
	int i,j;
	while(1)
	{
	    scanf("%d%d",&a,&b);
	    printf("\n");
	    scanf("%d",&input);
	    ar[a][b]=input;
	    for(i=0;i<2;i++)
	{
	    for(j=0;j<2;j++)
	    {
	        printf("%d\t",&ar[i][j]);
	    }
	    printf("\n");
	 }
	 if(ar[1][1]==ar[2][2]&&ar[2][2]==ar[3][3]&&ar[2][2]!=9)
	 {
	     printf("%d wins",ar[2][2]);
	     break;
	 }
	 else if(ar[1][3]==ar[2][2]&&ar[2][2]==ar[3][1]&&ar[2][2]!=9)
	 {
	     printf("%d wins",ar[2][2]);
	     break;
	 }

	}

	return 0;
}

