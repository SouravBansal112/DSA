#include<bits/stdc++.h>
using namespace std;

/*You have been given an undirected graph of ‘V’ vertices (labeled 0,1,..., V-1) and ‘E’ edges. Each edge connecting two nodes (‘X’,’Y’) will have a weight denoting the distance between node ‘X’ and node ‘Y’.

Your task is to find the shortest path distance from the source node, which is the node labeled as 0, to all vertices given in the graph. */
void buildAdjacency(unordered_map<int,list<pair<int,int>>> &adj, const vector<vector<int>> &edges, int n) {
    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w)); // Undirected graph
    }
}
vector<int> dijkstra(vector<vector<int>> &vec, int vertices,int edges,int source){
    unordered_map<int,list<pair<int,int>>> adj;
    buildAdjacency(adj,vec,vertices);

    vector<int> dist(vertices,INT_MAX);
    set<pair<int,int>> st;

    pair<int,int> src=make_pair(0,source);
    st.insert(src);
    dist[source]=0;

    while(!st.empty()){
        pair<int,int> top= *(st.begin());
        int distance = top.first;
        int node = top.second;
        st.erase(st.begin());

        for(auto i:adj[node]){
            if( distance + i.second < dist[i.first]){
                auto record=st.find(make_pair(dist[i.first], i.first));
                if(record != st.end()){
                    st.erase(record);
                }
                dist[i.first] = distance + i.second;
                st.insert(make_pair(dist[i.first],i.first));
            }
        }
    }
    return dist;
}







