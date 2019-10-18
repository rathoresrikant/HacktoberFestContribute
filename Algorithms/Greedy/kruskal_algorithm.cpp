//Kruskal algorithm
#include<iostream>
using namespace std;
int i,j,k,a,b,u,v,n,ne=1;
int mini,mincost=0,**cost,parent[9];
int funct_find(int i)
{
    while(parent[i])
    {
        i=parent[i];
    }
    return i;
}
int uni(int i,int j)
{
    if(i!=j)
    {
        parent[j]=i;
        return 1;
    }
    return 0;
}

int main()
{
    cout<<"Enter the number of vertices:";
    cin>>n;
    cost = new int*[n+1];
    for(i=0;i<=n;i++)
    {
        cost[i] = new int[n];
    }
    cout<<"Enter the adjacency matrix for graph:\n";
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>cost[i][j];
            if(cost[i][j]==0)
            cost[i][j]=999;

        }
    }
    cout<<"The edges of Minimum Cost Spanning Tree are"<<endl;
    while(ne < n)
    {
        for(i=1,mini=999;i<=n;i++)
        {
            for(j=1;j <= n;j++)
            {
                if(cost[i][j] < mini)
                {
                    mini=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        u=funct_find(u);
        v=funct_find(v);
        if(uni(u,v))
        {
            cout<<ne++<<" edge ("<<a<<","<<b<<")"<<mini<<endl;
            mincost +=mini;
        }
        cost[a][b]=cost[b][a]=999;
    }
    cout<<"Minimum cost="<<mincost;
    return 0;
}
