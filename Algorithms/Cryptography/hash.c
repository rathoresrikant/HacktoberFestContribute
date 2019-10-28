//hash function which generates hash value for unique set of characters 
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int myhash(char* a)
{
	int i, s=0;
	char ch;
	for(i=0;a[i]!='\0';i++)
		s+=a[i];//Summing ASCII values of the string
	s=s*i;//Multiplying by length
	return s;
}

int main()
{
	char a[]="Hacktober@PESOS";
	int s;
	printf("Text: %s\n", a);
	s=myhash(a);
	printf("Hash Value: %d\n", s);
	return 0;
}
