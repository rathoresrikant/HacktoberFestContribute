#include<iostream>
#include <climits>
template <typename T>
using namespace std;

class stack
{
	T* data;
	int nextIndex;
	int size;

public:
	stack()
	{
		data=new T[10];
		nextIndex=0;
		size=10;
	}
	void push(int e)
	{
		if(nextIndex==size)
		{
			T * newdata=new T[2*size];
			for(int i=0;i<size;i++)
				newdata[i]=data[i];
			delete []data;
			data=newdata;
			size=2*size;
		}
		data[nextIndex]=e;
		nextIndex++;
	}
	T pop()
	{
		if(isEmpty())
		{
			cout<<"EMPTY STACK";
			return 0;  
			//0 is returned as 0 is standard value for every data type
			//char-0=Null character
			//int,double-0=0
			//pointer- 0 means NULL POINTER eg: int * ptr=0
		}
		nextIndex--;
		return data[nextIndex];
	}
	T top()
	{
		if(isEmpty())
		{
			cout<<"EMPTY STACK";
			return 0;
		}
		return data[nextIndex-1];
	}
	int stacksize()
	{
		return nextIndex;
	}
	bool isEmpty()
	{
		return nextIndex==0;
	}
};