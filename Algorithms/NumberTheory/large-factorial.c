#include <stdio.h>
#define MAX 500

int multiply(int x, int result[], int res_size)
{
	int product, carry=0;

	for(int i = 0; i < res_size; i++){
		product = (result[i]*x) + carry;
		result[i] = product % 10;
		carry = product / 10;
	}

	while(carry){
		result[res_size] = carry%10;
		carry/=10;
		res_size++;
	}

	return res_size;
}

void factorial(int n)
{
	int result[MAX];
	result[0] = 1;

	int res_size = 1;

	for(int i = n; i >=2; i--){
		res_size = multiply(i, result, res_size);
	}

	for(int i = res_size -1; i >=0; i--)
		printf("%d", result[i]);
}

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d", &n);
		factorial(n);
		printf("\n");
	}
	
	return 0;
}
