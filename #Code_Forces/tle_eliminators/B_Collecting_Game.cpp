#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

bool cmp(pair<ll,int> &a,pair<ll,int> &b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    return a.first<b.first;
}

void solve(){
    int n; 
    cin >> n; 
    vector<ll> v(n);
    for(int i=0; i<n; i++) cin >> v[i];  
    vector<pair<ll,int>> vec(n);
    for(int i=0; i<n ; i++){
        vec[i].first=v[i];
        vec[i].second=i;
    }
    sort(vec.begin(),vec.end(),cmp);
    vector<ll> pref(n);
    pref[0]=vec[0].first;
    for(int i=1;i<n; i++){
        pref[i]=vec[i].first+pref[i-1];
        
    }
    vector<ll> ans(n);
    ans[vec[n-1].second]=n-1;
    for(int i=n-2; i>=0; i--){
        if(pref[i]>=vec[i+1].first){
            ans[vec[i].second]=ans[vec[i+1].second];
        }
        else{
            ans[vec[i].second]=i;
        }
    }
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
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