#include<bits/stdc++.h>
	int bin[100];
int main (){
	int a, tam=1, aux=0;
	scanf("%d", &a);
	while(a!=0){
		bin[tam]=a%2;
		a=a/2;
		tam++;
	}
	while(tam>0){
		printf("%d", bin[tam]);
		tam--;
	}
	puts("");
}
