#include <bits/stdc++.h> 
using namespace std;
/*You are given an array/list of ‘N’ integers. You are supposed to return the maximum sum of the subsequence with the constraint that no two elements are adjacent in the given array/list.*/
int memo(vector<int> &nums, vector<int> &dp, int n){
    if(n== nums.size()-1){
        return nums[nums.size()-1];
    }
    if(n>nums.size()-1){
        return 0;
    }
    if(dp[n]!=-1){return dp[n];}
    dp[n]=max(memo(nums,dp,n+2)+nums[n],memo(nums,dp,n+1));
    return dp[n];
}
/*
int tabu(vector<int> &nums){
    int n=nums.size();
    int prev2=0;
    int prev1=0;
    for(int i=n-1; i>=0 ; i--){
        int curr = max(prev2+nums[i],prev1);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}
*/
int maximumNonAdjacentSum(vector<int> &nums){

    vector<int> dp(nums.size(),-1);
    return memo(nums,dp,0);
    /*
    return tabu(nums);
    */
}










