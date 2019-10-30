#include <iostream>
using namespace std;
int a[10][10];
int abc(int size,int i,int j)
{
    for (int p = 0; p < size; p++) {
        for (int q = 0; q < size; q++) {
            if(i==p || j==q || (i+j)==(p+q)||(i-j)==(p-q)){
                if(a[p][q]==1)
                    return true;
            }
        }
    }
    return 0;
}
 
int Queen(int size,int n)
{
    if(n==0)
    return 1;
    
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(abc(size,i,j))
            continue;
            
            a[i][j]=1;
            
            if(Queen(size,n-1))
            return 1;
            a[i][j]=0;
        }
    }
    return 0;
}
 
int main() {
    int num;
	cin >> num;
	int size=num;
	for(int i=0;i<num;i++)
	{
	    for(int j=0;j<num;j++)
	    {
	       a[i][j]=0;
	    }
	}
	int ans=Queen(size,num);
	
	if(ans==1)
	{
	    for(int i=0;i<size;i++)
	    {
	        for(int j=0;j<size;j++)
	        {
	            cout<<a[i][j]<<" ";
	        }
	        cout<<endl;
	    }
	}
	else
	{
	    cout<<"Not possible";
	}
	return 0;
}
 
 
