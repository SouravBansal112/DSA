#include<bits/stdc++.h>
using namespace std;

int memo(vector<int> &arr,vector<int> &dp, int i,int &n){
    if(i>=n){
        return 0;
    }
    if(i==n-1){
        return arr[n-1];
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    dp[i]=arr[i]+memo(arr,dp,i+arr[i],n);
    return dp[i];
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n ; i++){
            cin>> arr[i];
        }
        int ans=0;
        vector<int> dp(n+1,-1);
        for(int i=0 ; i<n ; i++){
            ans=max(ans,memo(arr,dp,i,n));
            dp[i]=ans;
        }
        cout<<ans<<endl;
    }
}
