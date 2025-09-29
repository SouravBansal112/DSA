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
    int n; 
    cin >> n; 
    vector<vector<int>> dp(n,vector<int>(3));
    for(int i=0; i<n; i++) {
        int a,b,c;
        cin>>a>>b>>c;
        if(i==0){
            dp[0][0]=a;
            dp[0][1]=b;
            dp[0][2]=c;
        }
        else{
            dp[i][0]=max(a+dp[i-1][1],a+dp[i-1][2]);
            dp[i][1]=max(b+dp[i-1][0],b+dp[i-1][2]);
            dp[i][2]=max(c+dp[i-1][0],c+dp[i-1][1]);
        }
    }
    cout<<max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]))<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t=1;
  while(t--) solve();
  return 0;
}