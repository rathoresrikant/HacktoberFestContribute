#include<iostream>
#include<vector>
#include<queue>
using namespace std;


void addEdge(vector<vector<pair<int,int>>>& graph,int a,int b,int c)
{
    graph[a].push_back(make_pair(b,c));
    graph[b].push_back(make_pair(a,c));

}


vector<int> Dijkstra(vector<vector<pair<int,int>>> graph,int start)
{
    vector<int> dist(graph.size(),INT16_MAX);

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    
    pq.push(make_pair(start,0));
    dist[start] = 0;

    while(!pq.empty())
    {
        int u = pq.top().first;
        pq.pop();
        
        for(int i=0;i<graph[u].size();i++)
        {
            int v = graph[u][i].first;
            int wt = graph[u][i].second;
            if(dist[v]>dist[u]+wt)
            {
                dist[v] = dist[u]+wt;
                pq.push(make_pair(v,dist[v]));
            }

        }

    }
    return dist;

}
int main()
{

    int V=9;
    vector<vector<pair<int,int>>> graph(9,vector<pair<int,int>>(9));
    
    // Enter the elements 
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);
    
    vector<int> a = Dijkstra(graph,0);
    cout<<"src to dest.     distance"<<endl;
    for(int i=0;i<9;i++)
    {
        cout<<"0 to "<<i<<"         "<<a[i]<<endl;
    }


}