#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007;
typedef       long long     ll;

bool cmp(pair<int,int> &a,pair<int,int> &b){
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}

void solve(){
    int n; 
    cin >> n; 
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    int m;
    cin>>m;
    vector<pair<int,int>> q(m);
    for(int i=0; i<m; i++){
        cin>>q[i].first>>q[i].second;
    }
    vector<int> dp(n+1);
    dp[0]=-1;
    dp[1]= v[1]==v[0]? -1:0;
    for(int i=1; i<n; i++){
        if(v[i]!=v[i-1]){
            dp[i]=i-1;
        }
        else{
            dp[i]=dp[i-1];
        }
    }
    for(int i=0; i<m; i++){
        int s=q[i].first-1;
        int e=q[i].second-1;
        if(dp[e]>=s && dp[e]!=-1){
            cout<<dp[e]+1<<" "<<e+1<<endl;
        }
        else{
            cout<<-1<<" "<<-1<<endl;
        }
    }
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