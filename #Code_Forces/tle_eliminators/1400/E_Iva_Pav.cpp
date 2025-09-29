#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void get(int x,vector<int> &bits){
    int cnt=0;
    while(x!=0){
        bits[cnt]=x%2;
        x/=2;
        cnt++;
    }
}

void solve(){
    int n; 
    cin >> n; 
    vector<int> v(n);
    vector<vector<int>> dp(n,vector<int>(31,-1));
    for(int i=0; i<n; i++) cin>>v[i];

    for(int i=n-1; i>=0; i--){
        vector<int> bits(31);
        get(v[i],bits);
        for(int j=0; j<31; j++){
            if(bits[j]==1){
                if(i+1<n && dp[i+1][j]!=-1) dp[i][j]=dp[i+1][j];
                else dp[i][j]=i+1;
            }
        }
    }
    int m;
    cin>>m;
    for(int i=0; i<m; i++) {
        int l,x;
        cin>>l>>x;
        l--;
        if(v[l]<x){
            cout<<-1<<" ";
            continue;
        }
        int ans=l+1;
        set<int> s;
        for(int r=0; r<31; r++){
            if(dp[l][r]!=-1) s.insert(dp[l][r]);
        }
        for(auto r:s) {
            int num=0;
            for(int bit=0; bit<31; bit++){
                if(dp[l][bit]>=r) num+= 1<<bit;
            }
            if(num>=x) ans=max(ans,r);
        }
        cout<<ans<<" ";
    }cout<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}