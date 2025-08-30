#include <bits/stdc++.h> 
using namespace std;

/*You have been given a number of stairs. Initially, you are at the 0th stair, and you need to reach the Nth stair.
Each time, you can climb either one step or two steps.
You are supposed to return the number of distinct ways you can climb from the 0th step to the Nth step.
Note: Since the number of ways can be very large, return the answer modulo 1000000007.*/
int solve(int n, vector<int> &dp){
    if (n >= (int)dp.size()) return 0; 
    if (n == dp.size() - 1) return 1;
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n]=(solve(n+1,dp)+solve(n+2,dp))%1000000007;
    return dp[n];
    
}
int countDistinctWays(int nStairs) {
    if(nStairs==0){return 1;}
    int count=0;
    vector<int> dp(nStairs+1,-1);
    return solve(0,dp);
}

/*You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
You can either start from the step with index 0, or the step with index 1.
Return the minimum cost to reach the top of the floor.*/
int mincost(vector<int> &cost, vector<int> &dp,int n){
    if(n==0){
        return cost[0];
    }
    if(n==1){
        return cost[1];
    }
    if(n==cost.size()){
        dp[n]= min(mincost(cost,dp,n-1),mincost(cost,dp,n-2));
        return dp[n];
    }
    dp[n]= min(mincost(cost,dp,n-1),mincost(cost,dp,n-2)) + cost[n];
    return dp[n];
}
int minCostClimbingStairs(vector<int>& cost) {
    vector<int> dp(cost.size()+1,-1);
    return mincost(cost,dp,cost.size());
}
int solve3(vector<int> &cost,int n){
    int prev2=cost[0];
    int prev1=cost[1];
    int curr;
    for(int i=2; i<n;i++){
        curr= cost[i] + min(prev1,prev2);
        prev2=prev1;
        prev1=curr;
    }
    return min(prev1,prev2);
}
int minCostClimbingStair(vector<int>& cost) {
    int n=cost.size();
    return solve3(cost,n);
}



