#include<bits/stdc++.h>
using namespace std;
void tazan(int &timer,int node,vector<int> &disc, vector<int> &low, int parent, vector<bool> &vis, vector<vector<int>> &adj,vector<int> &result){
    disc[node]=timer;
    low[node]=timer++;
    vis[node]=true;
    for(auto nbr:adj[node]){
        if(nbr==parent){
            continue;
        }
        if(!vis[nbr]){
            tazan(timer,nbr,disc,low,node,vis,adj,result);
            low[node]=min(low[node],low[nbr]);

            if(low[nbr]>=disc[node]){
                result.push_back(node);
            }
        }
        else{
            low[node]=min(low[node],disc[nbr]);
        }
    }
}

vector<int> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<vector<int>> adj(n);
    vector<bool> visited(n);
    int parent=-1;
    int timer=0;
    vector<int> disc(n);
    vector<int> low(n);
    vector<int> result;
    for (auto &edge : connections) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }
    for(int i = 0; i<n ; i++){
        visited[i]=false;
        low[i]=-1;
        disc[i]=-1;
    }
    tazan(timer,0,disc,low,parent,visited,adj,result);
    return result;   
}

