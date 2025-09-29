#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007;
typedef       long long     ll;

void solve(){
    int n,x,y; 
    cin >> n>>x>>y; 
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    map<pair<int,int>,int> m;
    ll ans=0;
    for(int i=0; i<n; i++){
        pair<int,int> p= make_pair((x-v[i]%x)%x,v[i]%y);
        if(m.count(p)) ans+=(ll)m[p];
        p=make_pair(v[i]%x,v[i]%y);
        if(m.count(p)) m[p]++;
        else m[p]=1;
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