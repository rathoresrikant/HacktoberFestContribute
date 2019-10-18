// https://cp-algorithms.com/graph/bridge-searching.html
vector<vector<int>> adj;
vector<vector<int>> bridges;
vector<bool> visited;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
            if (low[to] > tin[v])
                bridges.push_back({v, to});
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                bridges.push_back({v, to});
        }
    }
}

void find_bridges(int n) {
    timer = 0;
    visited.resize(n, false);
    tin.resize(n, -1);
    low.resize(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]){
            cout << i << '\n';
            dfs(i);
        }
    }
}
