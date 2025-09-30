#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
#define       pb            push_back
typedef       long long     ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
const int n=40000, m=498;
ll dp[n+1][m+1];


bool palin(int n){
    int a=n;
    int b=0;
    int i=0;
    while(a>0){
        int dig=a%10;
        b= b*10+dig;
        a/=10;
        i++;
    }
    if(n==b) return true;
    return false;
}

void solve(){
    vector<int> v;
    v.push_back(0);
    for(int i=1; i<=n; i++){
        if(palin(i)) v.push_back(i);
    }    
    for(int j=0; j<=m; j++) dp[0][j] = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m ; j++){
            if(i-v[j]>=0) dp[i][j] = (dp[i][j]+(dp[i-v[j]][j]+dp[i][j-1])%MOD)%MOD;
            else dp[i][j]= (dp[i][j]+dp[i][j-1])%MOD;
        }
    }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  solve();
  while(t--){
    int x;
    cin>>x;
    cout<<dp[x][m]<<endl;
  }
  return 0;
}