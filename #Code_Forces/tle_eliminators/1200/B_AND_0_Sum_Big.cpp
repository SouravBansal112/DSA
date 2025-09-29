#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

ll modpow(ll n,ll k){
    ll res=1;
    while(k>0){
        if(k & 1) res= (res*n)%MOD;
        n=(n*n)%MOD;
        k=k>>1;
    }
    return res%MOD;
}

void solve(){
    ll n,k; 
    cin >> n>>k;
    ll ans=modpow(n,k);
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