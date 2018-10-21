

/*remove the vowels from string and return the new len
*/
//fist arg the string second is the len of the string(without the '\0')
int removeVowel(char* str,int len)
{
  if(len == 0 || str[0] =='\0')
    return 0;
    
  for(i=0; i<len; i++)
	{
  
		if((size != 0) && (tr[i]=='a' || str[i]=='e' || str[i]=='i' ||
		str[i]=='o' || str[i]=='u' || str[i]=='A' ||
		str[i]=='E' || str[i]=='I' || str[i]=='O' ||
		str[i]=='U'))
		{
			for(j=i; j<len; j++)
			{
				str[j]=str[j+1];
			}
		  len--;
      str[len+1]='\0';
		}
	}



  return len; 
}

