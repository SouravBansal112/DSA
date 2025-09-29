#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int b,g,n; 
    cin >> b>>g>>n;
    map<ll,vector<ll>> adj;
    vector<ll> guy(n);
    vector<ll> girl(n);
    for(int i=0; i<n; i++) cin>>guy[i];
    for(int i=0; i<n; i++) {cin>>girl[i]; girl[i]+=2e5;}
    ll ans=0;
    for(int i=n-1; i>=0; i--){
        int k=n-i;
        adj[guy[i]].push_back(girl[i]);
        adj[girl[i]].push_back(guy[i]);
        ans+= k-adj[guy[i]].size()-adj[girl[i]].size()+1;
    }
    cout<<ans<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}