#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n; 
    cin >> n; 
    vector<int> v(n+1);
    ll sum=0;
    for(int i=1; i<=n; i++) {cin>>v[i]; sum+=(ll)v[i];}
    vector<int> deg(n+1,0);
    for(int i=0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        deg[u]++;
        deg[v]++;
    }
    vector<int> ans;
    for(int i=1; i<=n; i++){
        for(int j=1; j<deg[i]; j++) ans.push_back(v[i]);
    }
    sort(ans.rbegin(),ans.rend());
    for(int i=0; i<ans.size();i++){
        cout<<sum<<" ";
        sum+=ans[i];
    }cout<<sum<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}