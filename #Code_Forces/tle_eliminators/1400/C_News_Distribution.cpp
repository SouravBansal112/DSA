#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

int find(int node, vector<int> &parent){
    if(parent[node]==node) return node;
    return parent[node]=find(parent[node],parent);
}

void unite(int u, int v,vector<int> &parent,vector<int> &rank){
    u=find(u,parent);
    v=find(v,parent);
    if(u==v) return;
    if(rank[u]<rank[v]){
        parent[u]=v;
        rank[v]++;
    }
    else if(rank[u]>rank[v]){
        parent[v]=u;
        rank[u]++;
    }
    else{
        parent[v]=u;
        rank[u]++;
    }

}

void solve(){
    int n,m; 
    cin >> n>>m;
    map<int,vector<int>> adj;
    vector<int> parent(n+1);
    vector<int> rank(n+1,0);
    for(int i=0; i<=n; i++) parent[i]=i;
    for(int i=0; i<m; i++){
        int k,u,v;
        cin>>k;
        if(k>0){
            cin>>u;
        }
        for(int j=0; j<k-1; j++){
            cin>>v;
            adj[u].push_back(v);
            unite(u,v,parent,rank);
        }
    }
    for(int i=1; i<=n; i++) find(i,parent);
    map<int,int> cnt;
    for(int i=1; i<=n; i++) cnt[parent[i]]++;
    for(int i=1; i<=n; i++){
        cout<<cnt[parent[i]]<<" ";
    }cout<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}