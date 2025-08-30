#include<bits/stdc++.h>
using namespace std;
int memo(int n,vector<int> &dp){
    if(n==0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int mini=n;
    for(int i=1 ; i*i<=n ; i++){
        mini = min(mini,1+memo(n-i*i,dp));
    }
    dp[n]=mini;
    return dp[n];
}
int tabu(int n){
    vector<int> dp(n+1,INT_MAX);
    dp[0]=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j*j<=n ; j++){
            if(i-j*j >=0){
                dp[i]=min(dp[i],1+dp[i-j*j]);   
            }
        }
    }
    return dp[n];
}
int MinSquares(int n) {
    vector<int> dp(n+1,-1);
    return tabu(n);
}