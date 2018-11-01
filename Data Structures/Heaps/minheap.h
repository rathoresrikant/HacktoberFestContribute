#include<iostream>
using namespace std;
class minheap
{
	int * arr;
	int size;

	void upheapify();
	void downheapify();
	void swap(int& a, int& b);

public:
	minheap()
	{
		arr= new int[10000];
		size=0;
	}
	void insert(int a);
	int getmin();
	int removemin();
	int getsize();
	void printheap();

};

void minheap::swap(int&a, int&b)
{
	int t=a;
	a=b;
	b=t;
}

void minheap::upheapify()
{
	int x=size;
	int y=(size-1)/2;
	if(y<0)
		return;
	while(y >= 0 && arr[y] > arr[x])
	{
		swap(arr[x],arr[y]);
		x=y;
		y=(x-1)/2;
	}

}

void minheap::downheapify()
{
	int x=0;
	int y=2*x + 1;
	int z=2*x + 2;
	int minpos;
	while((y<size && arr[x]>arr[y]) || (z<size && arr[x]>arr[z]))
	{
		if(y<size && z<size)
		{
			if(arr[y]<arr[z])
				minpos=y;
			else
				minpos=z;
		}
		else if(y<size)
		{
			minpos=y;
		}		

		swap(arr[minpos],arr[x]);
		x=minpos;
		y=2*x + 1;
		z=2*x + 2;

	}
}

void minheap::insert(int a)
{
	arr[size]=a;
	upheapify();
	size++;
}

int minheap::getmin()
{
	if(size==0)
		return -1;
	else
		return arr[0];
}

int minheap::getsize()
{
	return size;
}

int minheap::removemin()
{
	if(size==0)
		return -1;
	int k=arr[0];
	swap(arr[0], arr[size-1]);
	size--;
	downheapify();
	return k;

}

void minheap::printheap()
{
	for(int i=0;2*i+1<size||2*i+2<size;i++)
	{

		cout<<arr[i]<<" : ";
		if(2*i+1<size)
			cout<<arr[2*i+1]<<" , ";
		if(2*i+2<size)
			cout<<arr[2*i+2];
		cout<<endl;
	}
}

class PriorityQueue {
    vector<int> pq;
    
    public :
    
    PriorityQueue() {
        
    }
    
    bool isEmpty() {
        return pq.size() == 0;
    }
    
    // Return the size of priorityQueue - no of elements present
    int getSize() {
        return pq.size();
    }
    
    int getMin() {
        if(isEmpty()) {
            return 0;		// Priority Queue is empty
        }
        return pq[0];
    }
    
  	void swap(int&a, int&b)
	{
		int t=a;
		a=b;
		b=t;
	}
  
    void insert(int element) {
        pq.push_back(element);
        
        int childIndex = pq.size() - 1;
        
        while(childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;
            
            if(pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else {
                break;
            }
            childIndex = parentIndex;
        }
        
    }
    
    int removeMin() {
        // Complete this function
      int size=pq.size();
      if(size==0)
		return -1;
      
	  int k=pq[0];
	  swap(pq[0], pq[size-1]);
	  pq.pop_back();
      size--;
      
      
	int x=0;
	int y=2*x + 1;
	int z=2*x + 2;
	int minpos;
	while((y<size && pq[x]>pq[y]) || (z<size && pq[x]>pq[z]))
	{
		if(y<size && z<size)
		{
			if(pq[y]<pq[z])
				minpos=y;
			else
				minpos=z;
		}
		else if(y<size)
		{
			minpos=y;
		}		

		swap(pq[minpos],pq[x]);
		x=minpos;
		y=2*x + 1;
		z=2*x + 2;

	}
	  return k;
        
    }
    
    
};
