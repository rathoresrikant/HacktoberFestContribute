using namespace std;
//circular queue
template <typename T>
class queue
{
	T* data;
	int front;
	int rear;
	int size;
	int capacity;
public:
	queue(int s)
	{
		data=new T[s];
		front=-1;
		rear=0;
		size=0;
		capacity=s;
	}
	void enqueue(int element)
	{
		if(size==capacity)
		{
			T* newdata=new T[2*capacity];
			int j=0;
			for(int i=front;i<size;i++)
			{
				newdata[j]=data[i];
				j++;
			}
			for(int i=0;i<rear;i++)
			{
				newdata[j]=data[i];
				j++;
			}
			delete []data;
			data=newdata;
			capacity=capacity*2;
			front=0;
			rear=j;
		}
		data[rear]=element;
		if(front==-1)
			front=0;
		rear=(rear+1)%capacity;
		size++;
		
	}

	T dequeue()
	{
		if(isempty())
		{
			cout<<"queue empty"<<endl;
			return 0;
		}
		T ans=data[front];
		front=(front+1)%capacity;
		size--;
		if(size==0)
		{
			front=-1;
			rear=0;
		}
		return ans;
	}

	T getfront()
	{
		if(isempty())
		{
			cout<<"queue empty"<<endl;
			return 0;
		}
		return data[front];
	}

	int getsize()
	{
		return size;
	}

	bool isempty()
	{
		return size==0;
	}
};