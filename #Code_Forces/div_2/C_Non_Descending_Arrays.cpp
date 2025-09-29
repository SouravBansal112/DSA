#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
#define       mod           998244353
typedef       long long     ll;

void solve(){
    int n; 
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0; i<n; i++){ 
      cin>>a[i];
    }
    for(int i=0; i<n; i++){ 
      cin>>b[i];
    }
    if(n==1){
        cout<<2<<endl;
        return;
    }
    ll ans=1;
    for(int i=0; i<n; i++){
      if( (i-1>=0) && ((a[i]<a[i-1] && a[i]<b[i-1]) || (b[i]<b[i-1] && b[i]<a[i-1]))){
        ans=ans*0;
      }
      else if((i-1>=0 && a[i]>=a[i-1] && a[i]>=b[i-1] && b[i]>=b[i-1] && b[i]>=a[i-1])|| (i+1<n && a[i+1]>=a[i] && a[i+1]>=b[i] && b[i+1]>=b[i] && b[i+1]>=a[i])){
        ans= (ans*2)%mod;
      }
    }
    cout<<ans%mod<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}