#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n,x,m; 
    cin >> n>>x>>m;
    vector<pair<ll,ll>> v(m);
    for(int i=0; i<m; i++) cin>>v[i].first>>v[i].second;
    bool flag=false;
    pair<ll,ll> p=make_pair(LLONG_MAX,LLONG_MIN);
    for(int i=0; i<m; i++){
        if((x>=v[i].first && x<=v[i].second) || (v[i].first>=p.first && v[i].first<=p.second) || (v[i].second>=p.first && v[i].second<=p.second)){
            flag=true;
        }
        else flag = false;
        if(flag){
            if(v[i].first<p.first) p.first=v[i].first;
            if(v[i].second>p.second) p.second=v[i].second;
        }
    }
    if(p.first==LLONG_MAX){
        cout<<1<<endl;
        return;
    }
    cout<<p.second-p.first+1ll<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}