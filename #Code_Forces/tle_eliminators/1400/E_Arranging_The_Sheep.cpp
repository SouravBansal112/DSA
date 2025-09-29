#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n; 
    cin >> n; 
    string s;
    cin>>s;
    vector<int> pref(n);
    vector<int> succ(n);
    pref[0]= s[0]=='*'? 1:0;
    succ[n-1]= s[n-1]=='*'? 1:0;
    for(int i=1; i<n; i++){
        int x= s[i]=='*'?1:0;
        pref[i]=x+pref[i-1];
    }
    for(int i=n-2; i>=0; i--){
        int x= s[i]=='*'?1:0;
        succ[i]=x+succ[i+1];
    }
    ll gap=0;
    ll ans=0;
    for(int i=0; i<n; i++){
        if(s[i]=='.'){
            gap++;
            continue;
        }
        if(gap!=0){
            ans+= (ll)min(pref[i-1],succ[i-1])*gap;
            gap=0;
        }
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