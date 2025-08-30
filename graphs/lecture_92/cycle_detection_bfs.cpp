#include<bits/stdc++.h>
using namespace std;

void buildAdjacency(vector<vector<int>> &adj, const vector<vector<int>> &edges, int n, vector<int> &indegree) {
    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        indegree[v]++;
    }
}

bool bfsTrav(vector<vector<int>> &adj, vector<bool> &visited, int start, vector<int> &indegree) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int cnt = 0;

    while (!q.empty()) {
        int front = q.front();
        q.pop();
        cnt++;

        for (int neighbor : adj[front]) {
            indegree[neighbor]--;
            if (!visited[neighbor] && indegree[neighbor] == 0) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return cnt == 0; // cycle if we can't process any node
}

bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
    vector<vector<int>> adj(v);
    vector<bool> visited(v, false);
    vector<int> indegree(v, 0);

    buildAdjacency(adj, edges, v, indegree);

    int processedNodes = 0;
    queue<int> q;

    // Push all 0 indegree nodes
    for (int i = 0; i < v; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            visited[i] = true;
        }
    }

    while (!q.empty()) {
        int front = q.front();
        q.pop();
        processedNodes++;

        for (int neighbor : adj[front]) {
            indegree[neighbor]--;
            if (!visited[neighbor] && indegree[neighbor] == 0) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    // If we didn't process all nodes, there's a cycle
    return processedNodes != v;
}
