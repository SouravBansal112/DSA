#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    ll n,k; 
    cin >> n>>k; 
    vector<ll> v(n);
    ll mini=LLONG_MAX;
    for(int i=0; i<n; i++){
        cin>>v[i];
        mini=min(mini,v[i]);
    }
    if(k>2){cout<<0<<endl; return;}
    sort(v.begin(),v.end());
    set<ll> s;
    for(int i=0 ;i<n-1; i++){
        for(int j=i+1; j<n; j++){    
            ll x=v[j]-v[i];
            s.insert(x);
            mini=min(mini,x);
        }
    }
    if(k==1){cout<<mini<<endl; return;}
    for(auto i:s){
        int it= lower_bound(v.begin(),v.end(),i)-v.begin();
        ll x;
        if(it-1>=0 && it<n) x=min(i-v[it-1],v[it]-i);
        else if(it==0) x=v[it]-i;
        else x=i-v[n-1];
        mini=min(mini,x);
    }
    cout<<mini<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}