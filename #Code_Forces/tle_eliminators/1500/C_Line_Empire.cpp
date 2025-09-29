#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    ll n,a,b; 
    cin >> n>>a>>b; 
    vector<ll> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    vector<ll> pref(n); pref[0]=v[0];
    vector<ll> seg(n); seg[0]=v[0];
    for(int i=1; i<n; i++) {
        pref[i]=pref[i-1]+v[i];
        seg[i]=v[i]-v[i-1];
    }
    for(int i=1; i<n; i++) {
        seg[i]+=seg[i-1];
    }
    ll ans=b*pref[n-1];
    for(int i=0; i<n; i++) {
        ans=min(ans,(v[i]*a+b*(seg[i]+(pref[n-1]-pref[i])-(n-1-i)*v[i])));
    }cout<<ans<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}