#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
/*
vector<int> v(n);
for(int i=0 ; i<n ; i++){
    cin>>v[i];
}
*/
/*
for(int i=0 ; i<n ; i++){

}
*/
void solve(){
    int n,k,a,b; 
    cin >> n>>k>>a>>b;  // read input for the problem
    vector<pair<ll,ll>> v(n);
    for(int i=0; i<n; i++) cin >> v[i].first>>v[i].second;
    if(a<=k && b<=k){
        cout<<0<<endl;
        return;
    }
    ll init= abs(v[a-1].first-v[b-1].first)+abs(v[a-1].second-v[b-1].second);
    ll mini=LLONG_MAX;
    ll mini2=LLONG_MAX;
    for(int i=0; i<k; i++){
        ll dist1=abs(v[i].first-v[a-1].first);
        ll dist2=abs(v[i].second-v[a-1].second);
        mini=min(mini,dist1+dist2);
        dist1=abs(v[i].first-v[b-1].first);
        dist2=abs(v[i].second-v[b-1].second);
        mini2=min(mini2,dist1+dist2);

    }
    if(a>k && b>k){
        if(k==0){
            cout<<init<<endl;
            return;
        }
        cout<<min(init,mini+mini2)<<endl;
        return;
    }   
    if(a>k){
        cout<<mini<<endl;
        return;
    }
    else{
        cout<<mini2<<endl;
        return;
    }
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
