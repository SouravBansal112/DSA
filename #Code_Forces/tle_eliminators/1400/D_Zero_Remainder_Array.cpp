#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    ll n,k; 
    cin >> n>>k; 
    vector<ll> v(n);
    for(int i=0; i<n; i++) {
        cin>>v[i];
        v[i]%=k;
        if(v[i]!=0) v[i]=k-v[i];
    }
    sort(v.begin(),v.end());
    map<ll,ll> m;
    for(int i=0; i<n; i++) if(v[i]!=0) m[v[i]]++;
    // for(int i=0; i<n; i++) cout<<v[i]<<" ";
    // cout<<endl;
    ll ans=0;
    ll maxi=INT_MIN;
    ll sum=0;
    int x=0;
    for(auto i:m){
        if(maxi<i.second){
            maxi=i.second;
            x=i.first;
        }
        if(maxi==i.second && x<i.first){
            x=i.first;
        }
        sum+=i.second;
    }
    ans= (maxi-1)*k+x+1;
    if(maxi==INT_MIN) ans=0;
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