#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

void solve(){
    int n; 
    cin >> n; 
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    if(n==1){cout<<1<<endl; return;}
    int i=0;
    while(i+1<n && v[i]==v[i+1]){
        i++;
    }
    if(v[i]==v[i-1] && i==n-1){cout<<1<<endl; return;}
    bool inc=v[i]<v[i+1];
    int ans=0;
    for(int s=i+1; s<n; s++){
        if(inc){
            if(v[s]>=v[s-1]){
                continue;
            }
            else{
                ans++;
                inc=false;
            }
        }
        else{
            if(v[s]<=v[s-1]){
                continue;
            }
            else{
                ans++;
                inc=true;
            }
        }
    }
    ans+=2;
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