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
for(int i=0 ; i<n ; i++){tle eliminators

}
*/
bool check(ll &w,ll &x,ll &n,ll &c){
    if(w==0){return true;}
    if(w*n>c){
        return false;
    }
    if(w*w>c/n){
        return false;
    }
    if(x+n*w>c/w){return false;}
    return true;
}

void solve(){
    ll n,c; 
    cin >> n>>c;  // read input for the problem
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    ll x2=0;
    ll x=0;
    for(int i=0; i<n; i++){
        x+=v[i];
        x2+=v[i]*v[i];
    }
    c-=x2;
    c/=4;
    ll s=0;
    ll e=1e9;
    ll w=s+(e-s)/2;
    ll ans=0;
    while(s<=e){
        w=s+(e-s)/2;
        bool flag= check(w,x,n,c);
        if(flag){
            ans=w;
            s=w+1;
            if(x*w+w*w*n==c){
                break;
            }
        }
        else {
            e=w-1;
        }
    }
    cout<<ans<<endl;
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
