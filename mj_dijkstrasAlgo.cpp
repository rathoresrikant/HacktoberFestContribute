#include<bits/stdc++.h>
using namespace std;
void dijkstras()
{
    int n;
    cout<<"Enter the number of vertices ";
    cin>>n;
    int am[n][n];
    cout<<"Enter the adjacency matrix"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>am[i][j];
        }
    }

    int stnd;
    cout<<"Enter the starting node"<<endl;
    cin>>stnd;

    int cost[n][n],distance[n],path[n],visited[n],ct=0,nextnode,min_dist;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(am[i][j] == 0)
            {
                cost[i][j] = +1e5;
            }
            else
                cost[i][j] = am[i][j];
        }
    }

    for(int i=0;i<n;i++)
    {
        distance[i] = cost[stnd][i];
        path[i] = stnd;
        visited[i] = 0;
    }

    distance[stnd] = 0,visited[stnd] = 1;
    ct = 1;
    while(ct<n-1)
    {
        min_dist = +1e5;
        for(int i=0;i<n;i++)
        {
            if(distance[i]<min_dist && !visited[i])
            {
                min_dist = distance[i];
                nextnode = i;
            }
        }
        visited[nextnode]=1;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                if(min_dist + cost[nextnode][i]<distance[i])
                {
                    distance[i] = min_dist + cost[nextnode][i];
                    path[i] = nextnode;
                }
            }
        }
        ct++;
    }

    // print all the path

    for(int i=0;i<n;i++)
    {
        if(i!=stnd)
        {
            cout<<"\n Distance of node "<<i<<"="<<distance[i];
            cout<<"\n path = "<<i;
            int j = i;
            do
            {
                j = path[j];
                cout<<"<-"<<j;
            }while(j!=stnd);
        }
    }
}
int main()
{

    dijkstras();
    return 0;
}
