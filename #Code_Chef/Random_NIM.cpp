#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
/*
for(int i=0; i<n ;i++){
  
}
*/
/*
vector<int> v(n);
*/


long long modpow(long long a, long long e, long long mod) {
    long long res = 1;
    while (e > 0) {
        if (e & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        e >>= 1;
    }
    return res;
}

long long modinv(long long a, long long mod = MOD) {
    return modpow(a, mod - 2, mod);
}


int prob(int x,int &tot,bool player,vector<int> &dp){
    if(x==0){
        tot++;
        if(player){
            return 0;
        }
        else{
            return 1;
        }
    }
    if(dp[x]!=-1){return dp[x];}
    int ans=0;
    for(int i=1;i<=x; i++){
        ans+=prob(x-i,tot,!player,dp);
    }
    dp[x]=ans;
    return ans;
}

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n ; i++){
        cin>>v[i];
    }
    int wins=0;
    int tot=0;
    for(int i=0; i<n; i++){
        vector<int> dp(v[i]+1,-1);
        wins+=prob(v[i],tot,1,dp);
    }
        wins %= MOD;
        tot %= MOD;

        long long ans = (wins * modinv(tot)) % MOD;
        cout << ans << "\n";
  }
}