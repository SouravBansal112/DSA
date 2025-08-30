#include<bits/stdc++.h>
using namespace std;

/*You are given an undirected connected weighted graph having ‘N’ nodes numbered from 1 to 'N'. A matrix ‘E’ of size M x 2 is given which represents the ‘M’ edges such that there is an edge directed from node E[i][0] to node E[i][1]. You are supposed to return the minimum spanning tree where you need to return weight for each edge in the MST.*/
void buildAdjacency(unordered_map<int,list<pair<int,int>>> &adj, vector<pair<pair<int, int>, int>> &edges, int n) {
    for (auto &edge : edges) {
        int u = edge.first.first;
        int v = edge.first.second;
        int w = edge.second;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w)); // Undirected graph
    }
}

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int,list<pair<int,int>>> adj;
    buildAdjacency(adj,g,n);

    vector<int> key(n+1,INT_MAX);
    vector<bool> mst(n+1,false);
    vector<int> parent(n+1,-1);
    key[1]=0;
    vector<pair<pair<int,int>,int>> ans;

    for(int i = 1 ; i<=n ; i++){
        int mini=INT_MAX;
        int u;

        for(int j=1 ; j<=n; j++){
            if(mst[j] == false && key[j] < mini){
                mini=key[j];
                u=j;
            }
        }
        mst[u]=true;

        for(auto i:adj[u]){
            if(mst[i.first]==false && i.second < key[i.first]){
                key[i.first]=i.second;
                parent[i.first]=u;
            }
        }
    }

    for(int i =2; i<=n; i++){
        pair<int,int> p=make_pair(parent[i],i);
        ans.push_back(make_pair(p,key[i]));
    }
    return ans;
}
