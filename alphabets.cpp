#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <stack>
#include <unordered_map>
#include <iterator>
#include <algorithm>

using namespace std;

using Vertex = char;
using Vertices = set<Vertex>;
using AdjList = unordered_map<Vertex, Vertices>;

class Graph
{
  private:
    int numVertices;
    AdjList adjList;
    Vertices vertices;

  public:
    Graph(Vertices vertices);
    int getNumVertices() const;
    const Vertices &getVertices() const;
    void addEdge(Vertex from, Vertex to);
    void printAdjList();
    const Vertices &getNeighbours(Vertex vertex) const;
};

Graph::Graph(Vertices vertices)
    : vertices(vertices)
{
    numVertices = vertices.size();
    for (auto vertex : vertices)
    {
        adjList.insert(make_pair(vertex, set<Vertex>()));
    }
}

int Graph::getNumVertices() const
{
    return numVertices;
}

const Vertices &Graph::getVertices() const
{
    return vertices;
}
void Graph::addEdge(Vertex from, Vertex to)
{
    adjList[from].insert(to);
}

void Graph::printAdjList()
{
    cout << "AdjList:" << endl;
    for (auto i : adjList)
    {
        cout << i.first << " -> [ ";
        for (auto j : i.second)
            cout << j << " ";
        cout << " ]" << endl;
    }
}

const Vertices &Graph::getNeighbours(Vertex vertex) const
{
    auto res = adjList.find(vertex);
    return res->second;
}

void visitor(const Graph &graph, Vertex vertex, unordered_map<Vertex, bool> &visited, stack<Vertex> &s)
{
    visited[vertex] = true;
    auto neighbours = graph.getNeighbours(vertex);

    for (auto neighbour : neighbours)
    {
        auto visitItr = visited.find(neighbour);
        if (visitItr == visited.end() || visitItr->second == false)
            visitor(graph, neighbour, visited, s);
    }
    s.push(vertex);
}

void topologicalSort(const Graph &graph)
{
    stack<char> s;
    int numVertices = graph.getNumVertices();
    auto vertices = graph.getVertices();
    unordered_map<char, bool> visited;
    for (auto vertex : vertices)
    {
        auto visitItr = visited.find(vertex);
        if (visitItr == visited.end() || visitItr->second == false)
            visitor(graph, vertex, visited, s);
    }
    cout << "Sort Order:" << endl;
    while (s.empty() == false)
    {
        cout << s.top() << " ";
        s.pop();
    }
}

set<char> getAlphabets(vector<string> dict)
{
    set<char> alphabets;
    for (auto &word : dict)
    {
        for (int i = 0; i < word.size(); i++)
        {
            alphabets.insert(word[i]);
        }
    }
    return alphabets;
}
void createGraph(Graph &g, vector<string> dict)
{
    string w1, w2;
    int len;
    for (int i = 0; i < dict.size() - 1; i++)
    {
        w1 = dict[i];
        w2 = dict[i + 1];
        len = min(w1.size(), w2.size());
        for (int j = 0; j < len; j++)
        {
            if (w1[j] != w2[j])
            {
                g.addEdge(w1[j], w2[j]);
                break;
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);   // redirects standard input
    freopen("output.txt", "w", stdout); // redirects standard output
#endif
    vector<string> dict;
    string a;
    while (cin >> a)
        dict.push_back(a);

    Vertices alphabets = getAlphabets(dict);

    cout << "Alphabets: ";
    copy(alphabets.begin(), alphabets.end(), ostream_iterator<char>(cout, " "));
    cout << endl;

    Graph g(alphabets);
    createGraph(g, dict);

    g.printAdjList();
    topologicalSort(g);
}