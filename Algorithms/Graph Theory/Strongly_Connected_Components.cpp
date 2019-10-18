const int N = 1e5 + 5;

class Kosaraju{
  vi g[N], g_prime[N];
  bool vis[N];

  public:
    void add_edge(int u, int v){
      g[u].pb(v);
    }

    void reset(){
      memset(vis,0,sizeof vis);
    }

    void separate(int v, stack<int> &s){
      vis[v] = 1;
      for(auto x : g[v]){
        if(!vis[x]){
          separate(x,s);
        }
      }
      s.push(v);
    }

    void transpose(int n){
      for(int i = 0; i < n; i++){
        for(auto x : g[i]){
          g_prime[x].pb(i);
        }
      }
    }

    void dfs(int v, vi &tmp){
      vis[v] = 1;
      tmp.pb(v);
      for(auto x : g_prime[v]){
        if(!vis[x]){
          dfs(x,tmp);
        }
      }
    }

    vvi generate_SCC(int n){
      vvi SCC;
      stack<int> s;
      reset();
      for(int i = 0; i < n; i++){
        if(!vis[i])
          separate(i,s);
      }

      transpose(n); reset();

      while(!s.empty()){
        int v = s.top();
        s.pop();
        if(!vis[v]){
          vi tmp; dfs(v,tmp); SCC.pb(tmp);
        }
      }
      return SCC;
    }

};
