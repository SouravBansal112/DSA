#include<bits/stdc++.h>
using namespace std;


//map and list used
void printAdjacency(unordered_map<int,vector<int>> &adj, vector<vector<int>> &edges,int n) {
    int m = edges.size();
    // Build adjacency list in input order
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }
}

void bfsTrav(vector<int> &ans ,unordered_map<int,vector<int>> &adj,unordered_map<int,bool> &visited,int i){
    queue<int> q;
    q.push(i);
    visited[i] = true;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);
        // Process neighbors in input order
        for(auto j : adj[front]){
            if(!visited[j]){
                q.push(j);
                visited[j] = true;
            } 
        }
    }
}

vector<int> bfsTraversal(int vertex, vector<vector<int>> edges){
    unordered_map<int,vector<int>> adj;
    vector<int> ans;
    unordered_map<int,bool> visited;

    printAdjacency(adj,edges,vertex);

    for(int i=0 ; i<vertex ; i++){
        if(!visited[i]){
            bfsTrav(ans,adj,visited,i);
        }
    }
    return ans;
}

//vector used
void buildAdjacency(vector<vector<int>> &adj, const vector<pair<int,int>> &edges, int n) {
    for (auto &edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }
}

void bfsTrav(vector<int> &ans, vector<vector<int>> &adj, vector<bool> &visited, int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for (int neighbor : adj[front]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int,int>> edges) {
    vector<vector<int>> adj(vertex);
    vector<int> ans;
    vector<bool> visited(vertex, false);

    buildAdjacency(adj, edges, vertex);

    for (int i = 0; i < vertex; i++) {
        if (!visited[i]) {
            bfsTrav(ans, adj, visited, i);
        }
    }

    return ans;
}




