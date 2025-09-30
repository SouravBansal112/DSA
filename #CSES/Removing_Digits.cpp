#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
#define       pb            push_back
typedef       long long     ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

void getDig(vector<int> &v, int n){
    while(n>0){
        if(n%10>0) v.pb(n%10);
        n/=10;
    }
}

void solve(){
    int n; 
    cin >> n; 
    vector<int> dp(n+1,INT_MAX);
    dp[n]=0;
    for(int i=n; i>0; i--){
         if(dp[i]!=INT_MAX){
            vector<int> v;
            getDig(v,i);
            for(int j=0; j<v.size(); j++){
                if(i-v[j]>=0) dp[i-v[j]]= min(dp[i-v[j]],dp[i]+1);
            }
        }
    }cout<<dp[0]<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}