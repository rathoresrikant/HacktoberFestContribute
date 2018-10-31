#include<iostream>
using namespace std;
int main(){
	char str[100],updatedStr[100];
	cin>>str;
	int j=0;
	for(int i=0;i<100 && str[i]!='\0';i++){
		switch(str[i]){
			case 'a':
			case 'A':
			case 'e':
			case 'E':
			case 'i':
			case 'I':
			case 'o':
			case 'O':
			case 'u':
			case 'U':
			break;
			default: updatedStr[j++]=str[i];
		}
	}
	updatedStr[j]='\0';
	cout<<updatedStr;
	return 0;
}			
