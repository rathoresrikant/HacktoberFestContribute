#include <stdio.h>

int newmanconway(int n){
	if (n==1 || n==2){
		return 1;
	}
	else{
		return newmanconway(newmanconway(n-1))+newmanconway(n-newmanconway(n-1));
	}
}

int main(){
	int n;
	printf("Enter an integer\n");
	scanf("%d", &n);
	printf("%d\n", newmanconway(n));
	return 0;
}