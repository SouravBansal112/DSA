#include <bits/stdc++.h> 
using namespace std;

/*You are given an array of ‘N’ distinct integers and an integer ‘X’ representing the target sum. You have to tell the minimum number of elements you have to take to reach the target sum ‘X’.
You have an infinite number of elements of each type.*/
int tabu(vector<int> &num,int x){
    vector<int> dp(x+1,INT_MAX);
    dp[0]=0;
    for(int i=0; i<=x ; i++){
        for(int j=0; j<num.size(); j++){
            if(i-num[j]>=0 && dp[i-num[j]]!=INT_MAX){
                dp[i]= min(dp[i], 1+dp[i-num[j]]);
            }
        }
    }
    return dp[x];
}

int memo(vector<int> &num, vector<int> &dp, int x,int n){
    if(n==0){
        return 0;
    }
    if(n<0){
        return INT_MAX;
    }
    if(dp[n]!= -1){return dp[n];}
    int mini=INT_MAX;
    for(auto i:num){
        int ans = memo(num,dp,x,n-i);
        if(ans!=INT_MAX){
            mini=min(ans+1,mini);
        }
    } 
    dp[n]=mini;
    return dp[n];
}

int minimumElements(vector<int> &num, int x)
{
    /*vector<int> dp(x+1,-1);
    int ans=memo(num,dp,x,x);
    if(ans==INT_MAX){return -1;}
    return ans;
    */
    int ans=tabu(num,x);
    if(ans==INT_MAX){return -1;}
    return ans;
}