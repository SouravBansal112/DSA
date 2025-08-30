#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
/*
vector<int> v(n);
for(int i=0 ; i<n ; i++){
    cin>>v[i];
}
*/
/*
for(int i=0 ; i<n ; i++){

}
*/
void solve(){
    int n,k; 
    cin >> n>>k;
    vector<ll> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    sort(v.begin(),v.end());
    vector<ll> pref(n+1,0);
    vector<ll> suff(n+1,0);
    for(int i=0; i<n; i++){pref[i+1]=pref[i]+v[i];}
    for(int i=n-1; i>=0; i--){suff[n-i]=suff[n-i-1]+v[i];}

    ll tot=pref[n];
    ll ans=LLONG_MIN;
    for(int i=0;i<=k;i++){
        ll remove= suff[i] + pref[2*(k-i)];
        ans=max(ans,tot-remove);
    }
    cout<<ans<<endl;
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