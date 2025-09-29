#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
#define       pb            push_back
typedef       long long     ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

void solve(){
    int n,q; 
    cin >> n>>q; 
    vector<int> v(n+1);
    vector<int> pref(n+1,0);
    for(int i=1; i<=n; i++) cin>>v[i];
    for(int i=1; i<=q; i++) {
        int a,b; cin>>a>>b;
        pref[a]++; if(b+1<=n) pref[b+1]--;
    }
    map<int,int> m;
    for(int i=1; i<=n; i++){
        pref[i]+=pref[i-1];m[pref[i]]++;
    }
    sort(v.begin(),v.end());
    ll ans=0; int j=1;
    for(auto i:m){
        int sz= i.second;
        while(sz>0){
            ans+=(ll)((ll)i.first*(ll)v[j]); j++; sz--;
        }
    }cout<<ans<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}