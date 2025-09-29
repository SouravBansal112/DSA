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
    int n; 
    cin >> n; 
    vector<pair<pii,int>> v(n);
    for(int i=0; i<n; i++) {
        int a,b; cin>>a>>b; if(a>b) swap(a,b);
        v[i]={{a,b},i};
    }
    sort(v.begin(), v.end(), [&](const pair<pii,int> &a, const pair<pii,int> &b){
        if(a.first.second != b.first.second)
            return a.first.second < b.first.second;
        if(a.first.first != b.first.first)
            return a.first.first > b.first.first;
        return a.second < b.second;
    });
    int mini=v[n-1].first.first;
    int j=v[n-1].second;
    for(int i=n-2; i>=0; i--){
        if(v[i].first.first>=mini){
            cout<<v[i].second+1<<" "<<j+1<<endl; return;
        }
        else{
            mini=v[i].first.first;
            j=v[i].second;
        }
    }cout<<"-1 -1"<<endl;
}
 
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
