#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

bool check(vector<ll> &v,ll &k){
  set<ll> s;
  for(int i=0; i<v.size(); i++){
    if(s.size()>2) return false;
    if(s.count(v[i]%k))continue;
    s.insert(v[i]%k);
  }
  if(s.size()==2)return true;
  return false;
}

void solve(){
    int n; 
    cin >> n; 
    vector<ll> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    ll k=2;
    while(!check(v,k))k*=2;
    cout<<k<<endl;
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