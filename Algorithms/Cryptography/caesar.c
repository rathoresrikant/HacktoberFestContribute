//caesar cipher which returns value in uppercase
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void cshift(char* a, int shift)
{
	int i;
	char ch;
	for(i=0;a[i]!='\0';i++)
	{
		if(isalpha(a[i]))
		{
			ch=toupper(a[i]);//returns shifted value in uppercase
			ch=((ch+shift-65)%26)+65;//shifting
			a[i]=ch;
		}
	}
}

int main()
{
	char a[]="ATTACKATONCE";
	int shift=4;
	printf("Plain Text: %s\n", a);
	printf("Shift: %d\n", shift);
	cshift(a,shift);
	printf("Encrypted Text: %s\n", a);
	return 0;
}
