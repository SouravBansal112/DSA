#include<bits/stdc++.h>
using namespace std;

//Given a DAG(direct acyclic graph), return the Topological Sorting of a given graph.
void buildAdjacency(vector<vector<int>> &adj, const vector<vector<int>> &edges, int n,vector<int> &indegree) {
    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        indegree[v]++;
    }
}

void bfsTrav(vector<int> &ans, vector<vector<int>> &adj, vector<bool> &visited, int start, vector<int> &indegree) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for (int neighbor : adj[front]) {
            indegree[neighbor]--;
            if (!visited[neighbor] && indegree[neighbor]==0) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    vector<vector<int>> adj(nodes);
    vector<int> ans;
    vector<bool> visited(nodes, false);
    vector<int> indegree(nodes,0);

    buildAdjacency(adj, graph, nodes, indegree);

    for (int i = 0; i < nodes; i++) {
        if (!visited[i] && indegree[i]==0) {
            bfsTrav(ans, adj, visited, i, indegree);
        }
    }
    return ans;
}
