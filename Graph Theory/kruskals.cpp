#include<bits/stdc++.h>
using namespace std;
int arr[10000],rank1[10000];
int find1(int i){

    while(i!=arr[i]){
        i = arr[i];
    }

    return i;

}

void union1(int x,int y){


    if(rank1[x] < rank1[y]){
        arr[x] = y;
    }
    else if(rank1[x] > rank1[y]){
        arr[y] = x;
    }
    else{
        arr[y] = x;
        rank1[x]++;
    }


}


int main(){

    int n,m;
    cin>>n>>m;

    vector<pair<int,pair<int,int>>> edges;
    for(int i = 0;i<m;i++){

        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,{u,v}});

    }

    sort(edges.begin(),edges.end());

    vector<pair<int,int>> adj[n];
    int ctr = 0;
    for(int i = 0;i<n;i++){
        arr[i] = i;
        rank1[i] = 1;
    }
    int dist = 0;
    for(int i = 0;i<n-1;){

        pair<int,pair<int,int>> p = edges[ctr++];

        int weight = p.first;
        int u = p.second.first;
        int v = p.second.second;

        int paru = find1(u);
        int parv = find1(v);
        if(paru == parv){
            continue;
        }
        dist += weight;
        union1(paru,parv);
        adj[u].push_back({v,weight});
        adj[v].push_back({u,weight});
        i++;

    }
    cout<<dist<<endl<<endl;
    for(int i = 0;i<n;i++){
        cout<<i<<" : ";
        for(auto it = adj[i].begin();it!= adj[i].end();it++)
            cout<<it->first<<" ";
        cout<<endl;
    }


}
