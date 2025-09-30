#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
#define       pb            push_back
typedef       long long     ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
    int m,n; 
    cin >> m>>n; 
    vector<int> v(n+1); v[0]=0;
    for(int i=1; i<=n; i++) cin>>v[i];
    vector<int> curr(n+1,0);
    vector<int> prev(n+1,0);
    for(int i=1; i<=m; i++){
        for(int j=0; j<=n; j++) curr[j]=0;
        prev[0]=1;
        curr[0]=1;
        for(int j=1; j<=n ; j++){
            if(j-v[i]>=0) curr[j] = (curr[j]+curr[j-v[i]]+prev[j])%MOD;
            else curr[j]= (curr[j]+prev[j])%MOD;
        }
        prev=curr;
    }cout<<curr[n]<<endl;


    // for(int j=0; j<=m; j++) dp[0][j] = 1;
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=m ; j++){
    //         if(i-v[j]>=0) dp[i][j] = (dp[i][j]+dp[i-v[j]][j]+dp[i][j-1])%MOD;
    //         else dp[i][j]= (dp[i][j]+dp[i][j-1])%MOD;
    //     }
    // }cout<<dp[n][m]<<endl;
    return 0;
}