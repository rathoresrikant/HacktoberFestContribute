#include <iostream>
#include <vector>
#include <array>
#include <climits> // INT_MAX

using namespace std;

struct Node {
  int p = -1;
  int d = INT_MAX;
};

using edges_t = vector<array<int, 2>>;
using graph_t = vector<edges_t>;

// if a function of this type returns true, graph traversal will be interrupted
using edge_cb = bool(*)(vector<Node>&, int, int, int);

inline bool isNegativeCycle(vector<Node>& nodes, int u, int v, int w) {
  return nodes[v].d > nodes[u].d + w;
}

inline bool relaxNode(vector<Node>& nodes, int u, int v, int w) {
  // Relaxation
  if (nodes[v].d > nodes[u].d + w) {
    nodes[v].d = nodes[u].d + w;
    nodes[v].p = u;
  }

  return false;
}

// returns true if the traversal was successful
bool traverseAllEdges(const graph_t& graph, vector<Node>& nodes, edge_cb cb) {
  for (int u = 0; u < graph.size(); ++u) {
    const edges_t adjacent = graph[u];

    for (const auto& edge : adjacent) {
      int v = edge[0]; // Adjacent vertex
      int w = edge[1]; // Weight
  
      if (cb(nodes, u, v, w)) return false;
    }
  }

  return true;
}

bool bellmanFord(const graph_t& graph, int src, int dst, vector<int>& path) {
  const int len = graph.size();
  vector<Node> nodes(len);
  
  // Initialization
  for (int i = 0; i < len; ++i) {
    nodes[i] = Node();
  }
  
  nodes[src].d = 0;

  for (int i = 0; i < len; ++i) {
    traverseAllEdges(graph, nodes, relaxNode);
  }

  // Check for negative-weight cycles
  // Stop, if such cycles were detected
  if (!traverseAllEdges(graph, nodes, isNegativeCycle)) return false;

  // Construct the path from src to dst
  path.push_back(dst);

  Node node = nodes[dst];

  while (node.p != -1) {
    path.insert(path.begin(), node.p);
    node = nodes[node.p];
  } 

  return true;
}

int main() {
  graph_t graph(5, edges_t(3));

  graph[0] = {{1, 6}, {3, 7}};
  graph[1] = {{2, 5}, {3, 8}, {4, -4}};
  graph[2] = {{1, -2}};
  graph[3] = {{2, -3}, {4, 9}};
  graph[4] = {{0, 2}, {2, 7}};

  vector<int> path;

  if (bellmanFord(graph, 0, 2, path)) {
    for (const int& v : path) {
      cout << v << ' ';
    }
  } else {
      cout << "negative cycle detected\n";
  }
}
