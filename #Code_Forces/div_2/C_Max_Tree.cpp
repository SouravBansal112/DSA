#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

// int find(int x, vector<int> &parent) {
//     if (parent[x] == x) return x;
//     return parent[x] = find(parent[x], parent);
// }

// void unite(int u, int v, vector<int> &scnt, vector<int> &parent) {
//     u = find(u, parent);
//     v = find(v, parent);

//     if (u == v ) return;

//     parent[v] = u;

//     scnt[u] += scnt[v] + 1;
// }

void solve(){
    int n; 
    cin >> n;
    vector<vector<int>> adj(n+1);
    vector<int> indeg(n+1,0);
    for (int i=0; i<n-1; i++) {
        int u,v,x,y;
        cin >> u >> v >> x >> y;
        if (x > y) {
            adj[v].push_back(u);
            indeg[u]++;
        } else {
            adj[u].push_back(v);
            indeg[v]++;
        }
    }
    queue<int> q;
    for (int i=1; i<=n; i++) {
        if (indeg[i] == 0) q.push(i);
    }

    vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int nxt : adj[u]) {
            indeg[nxt]--;
            if (indeg[nxt] == 0) q.push(nxt);
        }
    }
    vector<int> ans(n+1);
    int cnt = 1;
    for (int u : order) {
        ans[u] = cnt++;
    }

    for (int i=1; i<=n; i++) cout << ans[i] << " ";
    cout <<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}