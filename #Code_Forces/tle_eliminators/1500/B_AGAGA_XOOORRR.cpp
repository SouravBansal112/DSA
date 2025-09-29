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
    vector<ll> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    vector<ll> pref(n);
    pref[0]=v[0];
    for(int i=1; i<n; i++){
      pref[i]=v[i]^pref[i-1];
    }
    for(int l=0; l<n; l++){
      for(int r=l; r<n; r++){
        ll a=pref[l];
        ll b=pref[r]^pref[l];
        ll c= pref[n-1]^pref[r];
        if(a==b && b==c){
          cout<<"YES"<<endl; return;
        }
      }
    }cout<<"NO"<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}