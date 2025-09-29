#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n; 
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    bool inc= v[0]<v[1];
    vector<int> ans;
    ans.push_back(v[0]);
    for(int i=1; i<n; i++){
        if(inc){
            if(v[i]>v[i-1]) continue;
            ans.push_back(v[i-1]);
            inc=!inc;
        }
        else{
            if(v[i]<v[i-1]) continue;
            ans.push_back(v[i-1]);
            inc=!inc;
        }
    }
    ans.push_back(v[n-1]);
    cout<<ans.size()<<endl;
    for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
    cout<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}