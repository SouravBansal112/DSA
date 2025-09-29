#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

void solve(){
    int n,x; 
    cin >> n>>x; 
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    sort(v.begin(),v.end());
    if(x<v[0]){cout<<0<<endl; return;}
    ll budget=x;
    ll cnt=0;
    ll ans=0;
    for(int i=0; i<n; i++){
        if(budget<v[i]) break;
        ll rem=(budget-v[i]+1);
        ans+= (rem+cnt)/(1+cnt);
        cnt++;
        budget=budget-v[i];
    }  
    cout<<ans<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--){
    solve();
  }
  return 0;
}