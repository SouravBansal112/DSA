#include<bits/stdc++.h>
using namespace std;

//top down dp = recursion + mpemoization
int fib(int n ,vector<int> &dp){
    if(n==1 || n==0){
        return n;
    }
    if(dp[n!= -1]){
        return dp[n];
    }
    dp[n]= fib(n-1,dp) +fib(n-2,dp);
    return dp[n];
}
//encapsulation
int fibonacci(int n){
    vector<int> dp(n+1,-1);
    return fib(n,dp);
}

//bottom uo dp= tabulation
int fibs(int n){
    vector<int> dp(n+1);
    dp[0]=0;
    dp[1]=1;
    for(int i =2 ; i<=n ; i++){
        dp[i]= dp[i-1] +dp[i-2];
    }
    return dp[n];
}

//space optimisation
int fibs(int n){
    int prev2=0;
    int prev1=1;
    if(n==0){
        return prev2;
    }
    for(int i =2 ; i<=n ; i++){
        int curr= prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}

