#include<bits/stdc++.h>
using namespace std;

void buildAdjacency(vector<vector<int>> &adj, const vector<vector<int>> &edges, int n) {
    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }
}

void solve(int &timer,int node,vector<vector<int>> &adj,int parent,vector<bool> &vis,vector<int> &disc,vector<int> &low,vector<vector<int>> &result){
    vis[node]=true;
    disc[node]=timer;
    low[node]=timer++;
    for(int neighbor:adj[node]){

        if(parent==neighbor){
            continue; 
        }

        if(!vis[neighbor]){
            solve(timer,neighbor,adj,node,vis,disc,low,result);
            low[node]=min(low[node],low[neighbor]);

            if(low[neighbor]>disc[node]){
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(neighbor);
                result.push_back(ans);
            }
        }
        else{
            low[node]=min(low[node],disc[neighbor]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    vector<vector<int>> adj(v);
    int parent=-1;
    vector<bool> visited(v,false);
    vector<int> disc(v,-1);
    vector<int> low(v,-1);
    vector<vector<int>> result;
    int timer=0;
    buildAdjacency(adj,edges,v);
    for(int i=0;i<v;i++){
        if(!visited[i]){
            solve(timer,0,adj,parent,visited,disc,low,result);
        }
    }
    return result;
}





