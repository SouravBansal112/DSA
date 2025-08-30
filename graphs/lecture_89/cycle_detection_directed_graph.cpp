#include <bits/stdc++.h>
using namespace std;

void buildAdjacency(vector<vector<int>> &adj, const vector<vector<int>> &edges) {
    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        //adj[v].push_back(u); // Undirected graph
    }
}

bool dfs(vector<bool> &visited, vector<bool> &dfsvis, vector<vector<int>> &adj, int node) {
    visited[node] = true;
    dfsvis[node]=true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            bool ans = dfs(visited, dfsvis, adj, neighbor);
            if(ans){ return true;}
        }
        else if(dfsvis[neighbor]==true){return true;}
    }
    dfsvis[node]=false;
    return false;
}

bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
    vector<vector<int>> adj(v);
    vector<bool> visited(v, false);
    vector<bool> dfsvis(v,false);

    buildAdjacency(adj, edges);

    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            if(dfs(visited,dfsvis, adj, i)) return true;

        }
    }
    return false;
}




