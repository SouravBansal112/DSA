#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n; 
    cin >> n;
    vector<int> odds;
    ll ans=0;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(x%2==0){
            ans+=x;
        }
        else{
            odds.push_back(x);
        }
    }
    if(odds.size()==0){
        cout<<0<<endl;
        return;
    }
    sort(odds.rbegin(),odds.rend());
    for(int i=0; i<(odds.size()+1)/2; i++){
        ans+=odds[i];
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