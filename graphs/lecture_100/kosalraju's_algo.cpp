#include<bits/stdc++.h>
using namespace std;

void rdfs(vector<bool> &visited, vector<vector<int>> &adj, int node) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            rdfs( visited, adj, neighbor);
        }
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

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	stack<int>stk;
	vector<bool> vis(v,0);
	vector<vector<int>> adj(v);
	vector<vector<int>> radj(v);
	for (int i=0; i<edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
	for(int i=0; i<v; i++){
		if(!vis[i]){
			dfs(vis,adj,i,stk);
		}
	}

	for(int i=0 ; i<v; i++){
		vis[i]=0;
		for(auto j:adj[i]){
			radj[j].push_back(i);
		}
	}

	int count= 0;
	while(!stk.empty()){
		int top= stk.top();
		stk.pop();
		if(!vis[top]){
			count++;
			rdfs(vis,radj,top);
		}
	}
    return count;
}



