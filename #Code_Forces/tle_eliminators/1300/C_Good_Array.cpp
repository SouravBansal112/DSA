#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n; 
    cin >> n;
    vector<ll> v(n);
    ll sum=0;
    map<ll,vector<int>> m;
    for(int i=0; i<n; i++){
        ll x;
        cin>>x;
        v[i]=x;
        m[x].push_back(i);
        sum+=x;
    }
    set<int> ans;
    for(int i=0; i<n; i++){
        ll x=sum-v[i];
        if(x<=v[i]) continue;
        ll need=x-v[i];
        if(m.count(need)){
            for(auto j:m[need]){
                if(j!=i) ans.insert(j);
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto i:ans) cout<<i+1<<" ";
    cout<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}