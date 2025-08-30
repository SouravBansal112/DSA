#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

void solve(){
    ll n; 
    cin >> n; 
    ll ans= (((n*n)%MOD+n)*(4*n-1)%MOD)*337%MOD;
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