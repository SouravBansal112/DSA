#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

bool pos(vector<pair<int,int>> &v, ll &mid){
    ll l=0;
    ll r=mid;
    for(int i=0; i<v.size(); i++){
        ll a=v[i].first;
        ll b=v[i].second;
        if(a>r || b<l){
            return false;
        }
        if(a>l){
           l=a-mid;
        }else l-=mid;
        if(b<r){
            r=b+mid;
        }else r+=mid;
    }
    return true;
}

void solve(){
    int n; 
    cin >> n; 
    vector<pair<int,int>> v(n);
    int mini=INT_MAX;
    int maxi=INT_MIN;
    for(int i=0; i<n; i++) {
        cin>>v[i].first>>v[i].second;
        mini= min(mini,min(v[i].first,v[i].second));
        maxi= max(maxi,max(v[i].first,v[i].second));
    }
    ll s=mini;
    ll e=maxi;
    ll mid=s+(e-s)/2;
    ll ans=0;
    while(s<=e){
        mid=s+(e-s)/2ll;
        if(pos(v,mid)){
            ans=mid;
            e=mid-1;
        }
        else s=mid+1;
    }
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