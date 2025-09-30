#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
#define       pb            push_back
typedef       long long     ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

void getSet(ll n,set<ll> &fact){
    ll temp=1;
    ll i=2;
    while(temp<=n){
        fact.insert(temp);
        temp*=i;
        i++;
    }
}

int getpow(ll n){
    int ans=0;
    while(n>0){
        if(n%2==1) ans++;
        n/=2;
    }
    return ans;
}

int rec(vector<ll> &v, int i, ll n){
    if(i>=v.size()){
        return getpow(n);
    }
    int ans=INT_MAX;
    if(v[i]<=n) ans=rec(v,i+1,n-v[i])+1;
    ans=min(ans,rec(v,i+1,n));
    return ans;
}

void solve(){
    ll n; 
    cin >> n; 
    set<ll> fact;
    getSet(n,fact);
    vector<ll> v(fact.begin(),fact.end());
    cout<<rec(v,0,n)<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}