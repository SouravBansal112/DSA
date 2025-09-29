#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

ll maxi(string s,char c,int n){
    vector<ll> pref(n);
    vector<ll> suff(n);
    pref[0]= (s[0]==c);
    suff[n-1]= (s[n-1]==c);
    for(int i=1; i<n; i++) {
        if(s[i]==c) pref[i]=pref[i-1]+1;
        else pref[i]=pref[i-1];
     }
    for(int i=n-2; i>=0; i--) {
        if(s[i]==c) suff[i]=suff[i+1]+1;
        else suff[i]=suff[i+1];
    }
    ll ans=0;
    ll gap=0;
    bool flag=false;
    for(int i=0; i<s.length(); i++){
        if(flag && s[i]!=c){
            gap++; continue;
        }
        if(s[i]==c){
            ans+= (ll)min(gap*(pref[i]-1),gap*(suff[i]));
            gap=0;
            flag=true;
        }
    }
    return ans;
}


void solve(){
    int n; 
    cin >> n; 
    string s; cin>>s;
    ll a= maxi(s,'a',n);
    ll b= maxi(s,'b',n);
    cout<<min(a,b)<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}