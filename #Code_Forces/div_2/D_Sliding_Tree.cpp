#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp(pair<int,int> &a, pair<int,int> &b){
    return a.second>b.second;
}

void buildAdjacency(vector<vector<int>> &adj, int n, vector<int> &deg) {
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
}

void solve(){
    int n;
    cin >> n;
    vector<int> deg(n + 1, 0);
    vector<vector<int>> adj(n + 1);
    buildAdjacency(adj, n, deg);

    for (int i = 1; i < n; i++) {
        sort(adj[i].begin(), adj[i].end(), [&](int a, int b) {
            if (deg[a] == deg[b]) return a<b;
            return deg[a] > deg[b];
        });
    }
    int maxi=1;
    for(int i=1; i<=n; i++){
        if(deg[i]>deg[maxi]){
            maxi=i;
        }
    }
    if(deg[maxi]<=2){
        cout<<-1<<endl;
        return ;
    }
    cout<<adj[maxi][0]<<" "<<maxi<<" "<<adj[maxi][1]<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--){
    solve();
  }
  return 0;
}