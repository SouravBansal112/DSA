#include <bits/stdc++.h> 
using namespace std;

/*Mr. X is a professional robber planning to rob houses along a street. Each house has a certain amount of money hidden.
All houses along this street are arranged in a circle. That means the first house is the neighbour of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses are broken into on the same night.
You are given an array/list of non-negative integers 'ARR' representing the amount of money of each house. Your task is to return the maximum amount of money Mr. X can rob tonight without alerting the police.*/
long long int tabu(vector<int> &nums){
    int n=nums.size();
    long long int prev2=0;
    long long int prev1=nums[0];
    for(int i=1; i<n ; i++){
        long long int curr = max(prev2+nums[i],prev1);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    int n=valueInHouse.size();
    if(n==1){return valueInHouse[0];}
    vector<int> dp(n,-1);
    vector<int> first,second;
    for(int i=0;i<n-1;i++){
        first.push_back(valueInHouse[i]);
        second.push_back(valueInHouse[i+1]);
    }
    long long int f=tabu(first);
    long long int s=tabu(second);
    return max(f,s);
}



