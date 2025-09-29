#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n; 
    cin >> n; 
    vector<pair<int,int>> edg(n-1);
    vector<int> deg(n+1,0);
    for(int i=0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        edg[i]={u,v};
        deg[u]++; deg[v]++;
    }
    int key=0;
    vector<int> ans(n-1,-1);
    for(int i=1; i<=n; i++){
        if(deg[i]>2) {key=i; break;}
    }
    int cnt=0;
    for(int i=0; i<n-1; i++) if(edg[i].first==key || edg[i].second==key){ans[i]=cnt; cnt++;}
    for(int i=0; i<n-1; i++) if(ans[i]==-1){ans[i]=cnt; cnt++;}
    for(int i=0; i<n-1; i++) cout<<ans[i]<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}