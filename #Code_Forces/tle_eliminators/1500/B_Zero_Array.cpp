#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n; 
    cin >> n; 
    vector<ll> v(n);
    ll sum=0;
    ll maxi=LLONG_MIN;
    for(int i=0; i<n; i++) {cin>>v[i]; sum+=v[i]; maxi=max(maxi,v[i]);}
    if(sum%2==0 && sum-maxi>= maxi) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}