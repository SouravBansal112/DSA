#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

void solve(){
    int n,q; 
    cin >> n>>q; 
    vector<int> v(n);
    vector<int> query(q);
    vector<ll> pref(n);
    vector<int> maxi(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
        if(i==0){
            maxi[0]=v[i];
        }else{
            maxi[i]=max(maxi[i-1],v[i]);
        }
    } 
    for(int i=0; i<q; i++) cin >> query[i];
    pref[0]=v[0];
    for(int i=1; i<n; i++){
        pref[i]=pref[i-1]+v[i];
    }
    for(int i=0; i<q;i++){
        auto it= upper_bound(maxi.begin(),maxi.end(),query[i]);
        if(it==maxi.begin()) cout<<0<<" ";
        else if(it==maxi.end()) cout<<pref[n-1]<<" ";
        else cout<<pref[it-maxi.begin()-1]<<" ";
    }cout<<endl;
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