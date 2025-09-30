#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
#define       pb            push_back
typedef       long long     ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

void solve(){
    string a,b; cin>>a>>b;
    int n=a.size(); int m= b.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    string ans="";
    vector<pair<int,int>> len;
    len.push_back({0,0});
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i-1]==b[j-1] ){
                dp[i][j]= dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]= max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    int i=n;
    int j=m;
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){ans=ans+a[i-1]; i--; j--;}
        else if(dp[i][j-1]>dp[i-1][j]) j--;
        else i--;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}