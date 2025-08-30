#include<bits/stdc++.h>
using namespace std;
template <typename T>
class graph{
    public:

    unordered_map<T,list<T>> adj;
    void addEdge(T u, T v,bool direction){
        adj[u].push_back(v);
        if(direction ==0){
            adj[v].push_back(u);
        }
    }
    void printAdjList(){
        for(auto i:adj){
            cout<< i.first << "->";
            for(auto j:i.second){
                cout<< j << ",";
            }
            cout<<endl;
        }
    }
};

/*You are given an undirected graph of 'N' nodes and 'M' edges. Your task is to create the graph and print the adjacency list of the graph. It is guaranteed that all the edges are unique, i.e., if there is an edge from 'X' to 'Y', then there is no edge present from 'Y' to 'X' and vice versa. Also, there are no self-loops present in the graph.



In graph theory, an adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a vertex in the graph.*/
vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges) {
    vector<vector<int>> ans(n);

    // Build adjacency list
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u); // Undirected graph
    }

    // Optional: If problem wants the vertex itself at start
    for (int i = 0; i < n; i++) {
        ans[i].insert(ans[i].begin(), i);
    }

    return ans;
}


