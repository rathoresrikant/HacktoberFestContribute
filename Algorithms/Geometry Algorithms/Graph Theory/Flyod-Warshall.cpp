// Floyd-Warshall algorithm is used to find the shortest path between all pairs of vertices of a graph

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;

	cout<<"Enter number of vertices: ";
	cin>>n;

	int dist[n][n];

	cout<<"Enter number of edges: ";
	cin>>m;

	while(m--)
	{
		int a,b,w;
		cout<<"Enter a edge between two vertices and its weight :";
		cin>>a>>b>>w;

		dist[a][b]=w;
		dist[b][a]=w;
	}

	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
		}
	}

}