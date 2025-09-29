#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    ll n; 
    cin >> n; 
    vector<ll> v(n);
    vector<ll> vec(n);
    for(int i=0; i<n; i++) cin>>v[i];
    for(int i=0; i<n; i++) cin>>vec[i];
    vector<ll> tp(n);
    tp[0]=vec[0];
    for(int i=1; i<n; i++) tp[i]=vec[i]+tp[i-1];
    vector<ll> ans(n,0);
    vector<ll> pref(n,0);
    for(int i=0; i<n ; i++){
      ll prev= i>0? tp[i-1]:0;
      int it= lower_bound(tp.begin(),tp.end(),v[i]+prev)-tp.begin();
      if(it==n) it--;
      if(it!=i){pref[i]++;pref[it]--;}
      prev= i-1>=0? (tp[it-1]-tp[i-1]): it-1>=0?tp[it-1]:0;
      ll x= min(vec[it],v[i]-prev);
      ans[it]+=x;
    }
    cout<<ans[0]+pref[0]*vec[0]<<" ";
    for(int i=1; i<n; i++){
      pref[i]+=pref[i-1];
      cout<<ans[i]+pref[i]*vec[i]<<" ";
    }cout<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}