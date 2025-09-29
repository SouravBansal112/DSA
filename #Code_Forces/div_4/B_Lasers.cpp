#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    ll n,m; 
    cin >> n>>m;
    vector<pair<int,int>> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i].first>>v[i].second;
    }
    int ans=0;
    for(int i=0; i<n; i++){
        int sub=0;
        int reach=0;
        if(i!=0) {
            sub=v[i-1].first;
            reach=v[i-1].second;
        }
        int dif=v[i].first-sub;
        bool same = v[i].second==reach;
        if(dif%2==0 && same){
            ans+=dif;
        }
        if(dif%2==0 && !same){
            ans+=dif-1;
        }
        if(dif%2==1 && same){
            ans+=dif-1;
        }
        if(dif%2==1 && !same){
            ans+=dif;
        }
    }
    if(v[n-1].first!=m){
        ans+=m-v[n-1].first;
    }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}