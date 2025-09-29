#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

void solve(){
    int n,m; 
    cin >> n>>m; 
    vector<int> v(m);
    for(int i=0; i<m; i++) cin >> v[i];
    sort(v.begin(),v.end());
    vector<int> gap;
    if(v[0]-1+n-v[m-1]>0){
        gap.push_back(v[0]-1+n-v[m-1]);
    }
    for(int i=1; i<m; i++){
        gap.push_back(v[i]-v[i-1]-1);
    }
    sort(gap.begin(),gap.end(),greater<int>());
    int ans=m;
    int cnt=0;
    for(int i=0; i<gap.size(); i++){
        int x=2*cnt+1;
        if(x==gap[i]){
            ans+=x-1;
        }
        else if(x<gap[i]){
            ans+=x;
        }
        else{
            ans+=gap[i];
        }
        cnt+=2;
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