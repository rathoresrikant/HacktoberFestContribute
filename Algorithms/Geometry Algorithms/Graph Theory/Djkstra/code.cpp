#include<bits/stdc++.h>
using namesapce std;
struct compare
{
bool operator(pair<int,int> p1,pair<int,int> p2)
{
	return p1.first>=p2.first;
}
};
int dijkstra(vector<pair<int,int> > v[],int s,int d,int n)
{
	int dis[n+1],vis[n+1];
	memset(vis,0,sizeof(vis));
	for(int i=0;i<=n;i++)
		dis[i]=INT_MAX;
	dis[s]=0;
	priority_queue<pair<int,int> ,vector<pair<int,int> > ,compare> q;
	q.push({0,s});
	while(!q.empty())
	{
		pair<int,int> node=q.top();
		q.pop();
		if(vis[node.second]==1)continue;
		if(node.second==d)return dis[d];
		vis[node.second]=1;
		for(auto it:v[node.second])
		{
			if(vis[it.first]==0&&dis[it.first]>dis[node.second]+node.first)
			{
				dis[it.first]=dis[node.second]+node.first;
				q.push({dis[it.first],it.first});
			}
		}
			
				   
	}
	return -1;
	
}
	

int main()
{
	int n,m;cin>>n>>m;
	vector<pair<int,int> > v[n+1];
	
	for(int i=1;i<=m;i++)
	{
		int wi,x,y;cin>>x>>y>>wi;
		v[x].push_back({y,wi});
		v[y].push_back({x,wi});
	}
	int source,destination;
	cin>>source>>destination;
	cout<<dijkstra(v,source,destination,n);
	return 0;
	
}
		
