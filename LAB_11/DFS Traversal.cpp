#include <iostream>
#include <list>
using namespace std;

class Graph {
private:
    int vertices;
    list<int>* adj;
    bool* visited;

public:
    Graph(int v) {
        vertices = v;
        adj = new list<int>[v];
        visited = new bool[v]{false};
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFS(int node) {
        visited[node] = true;
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor])
                DFS(neighbor);
        }
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    cout << "DFS Traversal: ";
    g.DFS(0);

    return 0;
}

