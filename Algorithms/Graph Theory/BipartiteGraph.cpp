#include <iostream>
using namespace std;

struct listnode {
    int key;
    struct listnode* next;
};

void addedge(struct listnode* adj[],int u ,int v){
    struct listnode* node = (struct listnode*)malloc(sizeof(struct listnode));
    node->key = v;
    node->next = adj[u-1];
    adj[u-1] = node;
    struct listnode* node1 = (struct listnode*)malloc(sizeof(struct listnode));
    node1->key = u;
    node1->next = adj[v-1];
    adj[v-1] = node1;
}

int DFS_visit(struct listnode* adj[],int arr[], int u){
    if(arr[u] == -1)arr[u] = 1;
    struct listnode* temp = adj[u];
    while(temp!= NULL){
        if(arr[temp->key -1] == -1){
            arr[temp->key - 1] = !arr[u];
            if(!DFS_visit(adj, arr, temp->key -1))return false;
            
        }
        else if(arr[temp->key - 1] == arr[u]){
            return false;
            
        }
        temp = temp->next;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int S,V,E,u,v,flag;
    cin>>S;
    while(S--){
        flag = 1;
        cin>>V>>E;
        struct listnode* adj[V];
        int arr[V];
        for(int i=0;i<V;i++){
            adj[i] = NULL;
            arr[i] = -1;
        }
        for(int i=0;i<E;i++){
            cin>>u>>v;
            addedge(adj, u, v); 
        }

        for(int i=0;i<V;i++){
            if(arr[i] == -1)flag = DFS_visit(adj, arr, i);
            if(!flag)break;
        }
        if(!flag)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}
