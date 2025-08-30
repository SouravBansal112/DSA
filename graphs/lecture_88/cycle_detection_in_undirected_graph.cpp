#include<bits/stdc++.h>
using namespace std;


/*You have been given an undirected graph with 'N' vertices and 'M' edges. The vertices are labelled from 1 to 'N'.

Your task is to find if the graph contains a cycle or not.

A path that starts from a given vertex and ends at the same vertex traversing the edges only once is called a cycle.*/

//this i bfs 0-n indexing version
void buildAdjacency(vector<vector<int>> &adj, const vector<vector<int>> &edges) {
    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }
}

bool cycle(vector<bool> &visited, vector<vector<int>> &adj, int node){
    queue<int> q;
    vector<int> p(adj.size());
    p[node]=-1;
    visited[node]=true;
    q.push(node);
    while(!q.empty()){
        int front = q.front();
        q.pop();
        // Process neighbors in input order
        for(auto j : adj[front]){
            if(visited[j] && j!=p[front]){
                return true;
            }
            if(!visited[j]){
                visited[j] = true;
                q.push(j);
                p[j]=front;
            } 
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<vector<int>> adj(n);
    vector<bool> visited(n, false);

    buildAdjacency(adj, edges);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if(cycle(visited, adj, i)) return "Yes";
        }
    }
    return "No";
}

//dfs version 1-n based indexing
void buildAdjacency(vector<vector<int>> &adj, const vector<vector<int>> &edges) {
    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1); // Undirected graph
    }
}

bool cycle(vector<bool> &visited, int parent, vector<vector<int>> &adj, int node) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            bool ans=cycle(visited, node, adj, neighbor);
            if(ans){
                return true;
            }
        }
        else if(neighbor!=parent){
            return true;
        }
    }
    return false;
}

string cycleDetections (vector<vector<int>>& edges, int n, int m)
{
    vector<vector<int>> adj(n);
    vector<bool> visited(n, false);

    buildAdjacency(adj, edges);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if(cycle(visited, -1, adj, i)) return "Yes";
        }
    }
    return "No";
}











