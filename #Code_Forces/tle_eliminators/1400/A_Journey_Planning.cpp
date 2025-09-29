#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n; 
    cin >> n; 
    map<int,ll> m;
    for(int i=1; i<=n; i++) {
        ll x;
        cin>>x;
        m[x-i]+=x;
    }
    ll maxi=LLONG_MIN;
    for(auto i:m) maxi=max(maxi,i.second);
    cout<<maxi<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t=1;
  while(t--) solve();
  return 0;
}