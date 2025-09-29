#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n; 
    cin >> n; 
    vector<int> v(n);
    int ans=0;
    int neg=0;
    int pos=0;
    for(int i=0; i<n; i++) {
        cin>>v[i];
        if(v[i]==0) ans++;
        if(v[i]<0) neg++;
    }
    if(neg%2==1) ans+=2;
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