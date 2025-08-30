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

void dfs(vector<bool> &visited, vector<vector<int>> &adj, int node,stack<int> &stk) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs( visited, adj, neighbor,stk);
        }
    }
    stk.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<vector<int>> adj(v);
    vector<int> ans;
    vector<bool> visited(v, false);
    stack<int> stk;

    buildAdjacency(adj, edges);

    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            dfs(visited, adj, i,stk);
        }
    }
    while(!stk.empty()){
        ans.push_back(stk.top());
        stk.pop();
    }

    return ans;
}



