#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* vow_rem(char str[]){
	int i;
	for(i=0; str[i]!='\0'; i++){
		switch(str[i]){
		case 'a':
  		case 'e':
   		case 'i':
   		case 'o':
   		case 'u':
   		case 'A':
   		case 'E':
   		case 'I':
   		case 'O':
   		case 'U':str[i]='~';	
		}
	}
	return str;
}
int main(){
	int j,k=0;
	char str1[30],str2[30];
	printf("\nENTER THE STRING: ");
	gets(str1);
	strcpy(str2,vow_rem(str1));
	for(j=0; str2[j]!='\0'; j++){
		if(str2[j]!='~'){
			str1[k]=str2[j];
			k++;
		}
	}
	str1[k]='\0';
	puts(str1);
	getch();
	return 0;
}
