#include <bits/stdc++.h>
using namespace std;

// Topological sort using DFS
void toposort(int node, vector<int>& visited, unordered_map<int, list<int>>& adjlist, stack<int>& s) {
    visited[node] = true;

    for (auto i : adjlist[node]) {
        if (!visited[i]) {
            toposort(i, visited, adjlist, s);
        }
    }
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>>& edges, int V, int e) {
    // Create an adjacency list
    unordered_map<int, list<int>> adjlist;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjlist[u].push_back(v);
    }

    stack<int> s;
    vector<int> visited(V, 0);

    // Perform DFS for all vertices
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            toposort(i, visited, adjlist, s);
        }
    }

    // Store the topological sort in the result vector
    vector<int> ans;
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

int main() {
    // Number of vertices and edges
    int V = 6, e = 6;

    // Define edges (u -> v)
    vector<vector<int>> edges = {
        {5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}
    };

    // Get the topological sort
    vector<int> result = topologicalSort(edges, V, e);

    // Print the result
    cout << "Topological Sort: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}