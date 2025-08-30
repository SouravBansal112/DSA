#include <bits/stdc++.h>
using namespace std;

void buildAdjacency(vector<vector<int>> &adj, const vector<vector<int>> &edges) {
    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }
}

void dfs(vector<int> &component, vector<bool> &visited, vector<vector<int>> &adj, int node) {
    visited[node] = true;
    component.push_back(node);
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(component, visited, adj, neighbor);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges) {
    vector<vector<int>> adj(V);
    vector<vector<int>> ans;
    vector<bool> visited(V, false);

    buildAdjacency(adj, edges);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            vector<int> component;
            dfs(component, visited, adj, i);
            ans.push_back(component);
        }
    }

    return ans;
}