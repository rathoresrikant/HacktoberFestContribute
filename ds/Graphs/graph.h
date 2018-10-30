#include<iostream>
using namespace std;

class graph
{
	int n;
	int e;
	int** g;
public:
	graph(int n,int e)
	{
		this->n=n;
		this->e=e;
		g=new int* [n];
		for(int i=0;i<n;i++)
		{
			g[i]=new int[n];
			for(int j=0;j<n;j++)
				g[i][j]=0;
		}

	}

	void AddEdges()
	{
		int s,d;
		for(int i=0;i<e;i++)
		{
			cin>>s>>d;
			g[s][d]=1;
			g[d][s]=1;
		}
	}

	void RemoveEdge()
	{
		int s, d;
		cout<<"Enter Vertices:"<<endl;
		cin>>s>>d;
		g[s][d]=0;
		g[d][s]=0;
	}
private:

  void DFS(int start,bool* visited)
	{
		cout<<start<<" ";
		visited[start]=true;

		for(int i=0;i<n;i++)
		{
			if(g[start][i])
			{
				if(!visited[i])
					DFS(i,visited);
			}
		}

	}



  void BFS(int start,bool* visited)
  {
    
    visited[start]=true;
    queue<int> q;
    q.push(start);
    
    while(!q.empty())
    {
      int k=q.front();
      q.pop();
      cout<<k<<" ";
      for(int i=0;i<n;i++)
      {
        if(g[k][i])
        {
          if(!visited[i])
          {
            q.push(i);
            visited[i]=true;
          }
        }
      }
    }
    
  }
  
  
public:
  //Question1
  void BFS()
  {
    bool* visited=new bool[n];
    for(int i=0;i<n;i++)
      visited[i]=false;
    for(int i=0;i<n;i++)
      if(!visited[i])
    	BFS(i,visited);
  }

  //Question2
  void DFS()
	{
		int s;
		cout<<"Enter Starting Index:"<<endl;
		cin>>s;
		bool* visited=new bool[n];
		for(int i=0;i<n;i++)
			visited[i]=false;
		//It is made considering the disconnected components of graph. 
	for(int i=0;i<n;i++)
      if(!visited[i])
    	DFS(i,visited);

	}

  //Question3
	bool haspathDFS(bool* visited,int v1,int v2)
	{
	  if(v1==v2)
	    return true;
	  visited[v1]=true;
	  bool b;
     	for(int i=0;i<n;i++)
		{
			if(g[v1][i])
			{
              	if(v1==i)
                  continue;
				if(!visited[i])
                {
                  b=haspath(visited,i,v2);
              	  if(b==true)
                    return true;
                }
			}
		}
  	  return false;
	}

  //Question4
	vector<int>* getpathDFS(bool* visited,int v1,int v2)
	{
	  if(v1==v2)
      {
	    vector<int> * t= new vector<int>;
        t->push_back(v1);
        return t;
      }
	  visited[v1]=true;
	  vector<int> * b= new vector<int>;

     	for(int i=0;i<n;i++)
		{
			if(g[v1][i])
			{
              	if(v1==i)
                  continue;
				if(!visited[i])
                {
                  b=getpathDFS(visited,i,v2);
              	  if(b->empty())
                    continue;
                  else
                  {
                    b->push_back(v1);
                    return b;
                  }
                }
			}
		}
  	  return b;
	}

  //Question5
	vector<int> getpathBFS(int s,int e,bool* visited)
  {
    unordered_map<int,int> m;
    visited[s]=true;
    queue<int> q;
    q.push(s);
    int flag=0;
    while(!q.empty())
    {
      int k=q.front();
      q.pop();
      for(int i=0;i<n;i++)
      {
        if(g[k][i])
        {
          if(!visited[i])
          {
            m[i]=k;
            q.push(i);
            visited[i]=true;
            if(i==e)
            {
              flag=1;
              break;
            }
          }
        }
      }
      
      if(flag==1)
      {
        break;
      }
    }
    
  vector<int> path;
  if(flag==1)
  {
  int k=e;
  while(s!=k)
  {
    path.push_back(k);
    k=m[k];
  }
  path.push_back(s);
  }
  return path;
    
  }

  //Question6
	bool isConnected()
	{
		int s;
		bool* visited=new bool[n];
		for(int i=0;i<n;i++)
			visited[i]=false;
        DFS(0,visited);

		for(int i=0;i<n;i++)
      		if(!visited[i])
              return false;
      	return true;

	}

	//Question7
	vector<int> DFS_CC(int start,bool* visited)
	{
      	vector<int> b;
      	vector<int> temp;
      	b.push_back(start);
		visited[start]=true;
		for(int i=0;i<n;i++)
		{
			if(g[start][i])
			{
				if(!visited[i])
                {
                  temp=DFS(i,visited);
                  for(int i=0;i<temp.size();i++)
                    b.push_back(temp[i]);
                }
			}
		}
		return b;
     }
  
  	vector<vector<int>> ConnectedComponents()
	{
		int s;
      	vector<vector<int>> v;
      	vector<int> t;
		bool* visited=new bool[n];
		for(int i=0;i<n;i++)
			visited[i]=false;
		for(int i=0;i<n;i++)
      		if(!visited[i])
            {
              t=DFS(i,visited);
              v.push_back(t);
            }

      	return v;

	}
  
};

