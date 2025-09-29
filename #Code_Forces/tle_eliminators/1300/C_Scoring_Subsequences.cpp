#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void solve(){
    int n; 
    cin >> n; 
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    vector<int> dp(n);
    dp[0]=1;
    for(int i=1; i<n; i++){
        int s=0;
        int e=i;
        int mid= s+(e-s)/2;
        int ans=e;
        while(s<=e){
            mid=s+(e-s)/2;
            if(v[mid]>=i-mid+1){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        dp[i]=i-ans+1;
    }
    for(int i=0; i<n; i++) cout<<dp[i]<<" ";
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