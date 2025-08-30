#include<bits/stdc++.h>
using namespace std;

/*A Derangement is a permutation of ‘N’ elements, such that no element appears in its original position. For example, an instance of derangement of {0, 1, 2, 3} is {2, 3, 1, 0}, because 2 present at index 0 is not at its initial position which is 2 and similarly for other elements of the sequence.
Given a number ‘N’, find the total number of derangements possible of a set of 'N’ elements.
The answer could be very large, output answer %(10 ^ 9 + 7).*/
long long int memo(int n,vector<int> &dp){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=((n-1)*(memo(n-1,dp)+memo(n-2,dp))) % 1000000007;
    return dp[n];
}

long long int tabu(int n){
    long long int prev1=1;
    long long int prev2=0;
    if(n==2){return 1;}
    for(int i=3; i<=n; i++){
        long long int curr = ((i-1)*(prev1+prev2)) % 1000000007;
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}

long long int countDerangements(int n) {
    if(n==0 || n==1){return 0;}
    return tabu(n);
}