#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    ll n,m; 
    cin >> n>>m; 
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    sort(v.begin(),v.end(),greater<int>());
    ll ans=0;
    for(int i=0; i<n && m>0 ; i++){
        ans+= (ll)v[i]*m;
        m--;
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