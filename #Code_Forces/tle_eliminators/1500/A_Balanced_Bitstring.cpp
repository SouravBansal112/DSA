#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n,k; 
    cin >> n>>k; string s; cin>>s;
    for(int i=0; i<n-(n-k); i++){
      int one=0;
      int zero=0;
      int q=0;
      for(int j=i; j<n; j+=k){
        if(s[j]=='?') q++;
        else if(s[j]=='0') zero++;
        else one++;
      }
      if(zero && one){cout<<"NO"<<endl; return;}
      if(zero) s[i]='0';
      else if(one) s[i]='1';
    }
    int one=0;
    int zero=0;
    int q=0;
    for(int i=0; i<n-(n-k); i++){
      if(s[i]=='?') q++;
      else if(s[i]=='0') zero++;
      else one++;
    }
    ll d= abs(one-zero);
    if(d<=q && (q-d)%2==0 ){
      cout<<"YES"<<endl; return;
    }
    cout<<"NO"<<endl; 
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}