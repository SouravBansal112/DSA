#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

int msb(ll x){
    int msb=0;
    while(x>0){
        x/=2;
        msb++;
    }
    return msb;
}

void solve(){
    ll n; 
    cin >> n; 
    ll ans=0;
    ll lim= msb(n);
    for(ll i=0; i<=lim; i++){
        ans+= (n)/(1ll<<i);
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