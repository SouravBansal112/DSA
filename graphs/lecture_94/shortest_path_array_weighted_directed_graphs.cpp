#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
    unordered_map<int,list<pair<int,int>>> adj;

    void addEdge(int u, int v,int weight){
        pair<int,int> p=make_pair(v,weight);
        adj[u].push_back(p);
    }

    void printadj(){
        for(auto i:adj){
            cout<< i.first<< "->";
            for(auto j:i.second){
                cout<< "["<<j.first<<" ,"<<j.second<<" ],";
            }
            cout<<endl;
        }
    }

    void dfs(unordered_map<int,bool> &visited,int node,stack<int> &stk) {
        visited[node] = true;
        for (auto neighbor : adj[node]) {
            if (!visited[neighbor.first]) {
                dfs( visited, neighbor.first,stk);
            }
        }
        stk.push(node);
    }

    void getShortestPath(int src,vector<int> &dis, stack<int> &stk){
        dis[src]=0;
        while(!stk.empty()){
            int top=stk.top();
            stk.pop();
            if(dis[top]!=INT_MAX){
                for(auto i:adj[top]){
                    if(dis[top] + i.second < dis[i.first] ){
                        dis[i.first] = dis[top] + i.second;
                    }
                }

            }
        }
    }
};

int main(){
    graph g;
    int n,edges;
    cin>>n>>edges;
    while(edges--){
        int u,v,w;
        cin>>u>>v>>w;
        g.addEdge(u,v,w);
    }
    stack<int> stk;
    unordered_map<int,bool> visited;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            g.dfs(visited,i,stk);
        }
    }
    int src=0;
    vector<int> dis(n,INT_MAX);
    g.getShortestPath(src,dis,stk);
    return 0;
}




