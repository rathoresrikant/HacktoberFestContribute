#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void perfect_number(int l,int r);

int main(){

int l,r;
printf("Enter range in (low,high) format\n");
scanf("%d%d",&l,&r);
perfect_number(l,r);
return 0;
}

void perfect_number(int l,int r){

	int find_divisors_sum(int num){
		
		int limit=ceil(num/2),sum=1;
		for(int i=2;i<=limit;i++){
			if(num%i==0){
				sum+=i;
			}
		}
	return sum;
	}

	

	int proper_div_sum;
	printf("Perfect numbers are\n");
	for(int i=l;i<=r;i++){
		proper_div_sum=find_divisors_sum(i);
		if((proper_div_sum==i)&&(proper_div_sum+i)/2==i){
			printf("%d\n",i);
		}
	}
	


}


					
