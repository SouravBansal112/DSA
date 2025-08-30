#include<bits/stdc++.h>
using namespace std;
//undirected
void buildAdjacency(vector<vector<int>> &adj, const vector<pair<int,int>> &edges, int n) {
    for (auto &edge : edges) {
        int u = edge.first-1;
        int v = edge.second-1;
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }
}

void bfsTrav(int vertex, vector<pair<int,int>> &edges,vector<int> &parent,int s) {
	vector<vector<int>> adj(vertex);
    vector<bool> visited(vertex, false);
	buildAdjacency(adj, edges, vertex); 

	queue<int> q;
	q.push(s);
	visited[s] = true;

	while (!q.empty()) {
		int front = q.front();
		q.pop();

		for (int neighbor : adj[front]) {
			if (!visited[neighbor]) {
				visited[neighbor] = true;
				parent[neighbor]=front;
				q.push(neighbor);
			}
		}
	}         
}

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	vector<int> parent(n,-1);
	vector<int> ans;
	bfsTrav(n,edges,parent,s-1);
	int x=t-1;
	while(x!=s-1){
    	ans.push_back(x+1);
		x=parent[x];
	}	
	ans.push_back(s);
	reverse(ans.begin(),ans.end());
	return ans;
}








