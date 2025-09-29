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
    vector<pii> v(n);
    for(int i=0; i<n; i++) {
        int a,b; cin>>a>>b; v[i]={a,b};
    }
    map<int,int> m;
    for(int i=0; i<n; i++){
        m[v[i].first]++;
        m[v[i].second+1]--;
    }
    int prev=0;
    for(auto &i:m){
        i.second=i.second+prev;
        prev=i.second;
    }
    for(auto i:m){
        if(i.second>2){
            cout<<"NO"<<endl; return;
        }
    }cout<<"YES"<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}