#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

void divide(int x,ll &div,string &s, vector<bool> &vis,ll &ans){
    while(!vis[x-1]){
        for(int i=1; div*i<=s.length(); i++){
            int x=div*i;
            if(s[x-1]=='1'){
                break;
            }
            if(vis[x-1]){
                continue;
            }
            else{
                vis[x-1]=true;
                ans+=div;
            }
        }
        div++;
    }
}

void solve(){
    int n; 
    cin >> n; 
    string s;
    cin>>s;
    vector<bool> vis(n,false);
    ll div=1;
    ll ans=0;
    for(int i=0; i<n; i++){
        if(vis[i] || s[i]=='1'){
            continue;
        }
        if(s[i]=='0'){
            divide(i+1,div,s,vis,ans);
        }
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