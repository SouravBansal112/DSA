#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n,k; 
    cin >> n>>k; 
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    int ans=0;
    int cnt=0;
    int key=0;
    vector<int> vis(k,0);
    for(int i=0; i<n; i++) {
        if(v[i]==k){
            key++; continue;
        }
        if(v[i]<k) vis[v[i]]++;
    }
    for(int i=0;i<k ;i++){
        if(vis[i]<1) cnt++;
    }
    if(cnt>=key){
        cout<<cnt<<endl;
    }
    else{
        cout<<cnt+(key-cnt)<<endl;
    }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}