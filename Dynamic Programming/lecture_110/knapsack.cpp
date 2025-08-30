#include <bits/stdc++.h>
using namespace std;

//A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and the ith item weighs wi and is of value vi. Considering the constraints of the maximum weight that a knapsack can carry, you have to find and return the maximum value that a thief can generate by stealing items.
#include <bits/stdc++.h>
using namespace std;
int memo(vector<int> &weight, vector<int> &val, int i, int W,vector<vector<int>> &dp){
	if(i==0){
		if(weight[i]<=W){
			return val[i];
		}
		else{
			return 0;
		}
	}
	if(dp[i][W]!=-1){
		return dp[i][W];
	}
	int inc=INT_MIN;
	if(weight[i]<=W){
		inc=val[i]+memo(weight,val,i-1,W-weight[i],dp);
	}
	int exc=memo(weight,val,i-1,W,dp);
	dp[i][W]=max(inc,exc);
	return dp[i][W];


}

int tabu(vector<int> weight, vector<int> value, int n, int capacity){
	vector<vector<int>> dp(n,vector<int>(capacity+1,0));
	for(int i=weight[0]; i<=capacity; i++){
		if(weight[0]<= capacity){
			dp[0][i]=value[0];
		}
		else{
			dp[0][i]=0;
		}
	}
	for(int i=1 ; i<n ; i++){
		for(int j=0; j<=capacity; j++){
			int inc=0;
			if(weight[i]<=j){
				inc=value[i]+dp[i-1][j-weight[i]];
			}
			int exc=dp[i-1][j];
			dp[i][j]=max(inc,exc);
		}
	}
	return dp[n-1][capacity];
}

int tabuOptimised(vector<int> weight, vector<int> value, int n, int capacity){
	vector<int> prev(capacity+1,0);
	vector<int> curr(capacity+1,0);
	for(int i=weight[0]; i<=capacity; i++){
		if(weight[0]<= capacity){
			prev[i]=value[0];
		}
		else{
			prev[i]=0;
		}
	}
	for(int i=1 ; i<n ; i++){
		for(int j=0; j<=capacity; j++){
			int inc=0;
			if(weight[i]<=j){
				inc=value[i]+prev[j-weight[i]];
			}
			int exc=prev[j];
			curr[j]=max(inc,exc);
		}
		prev=curr;
	}
	return prev[capacity];
}

int tabuMoreOptimised(vector<int> weight, vector<int> value, int n, int capacity){
	vector<int> curr(capacity+1,0);
	for(int i=weight[0]; i<=capacity; i++){
		if(weight[0]<= capacity){
			curr[i]=value[0];
		}
		else{
			curr[i]=0;
		}
	}
	for(int i=1 ; i<n ; i++){
		for(int j=capacity; j>=0; j--){
			int inc=0;
			if(weight[i]<=j){
				inc=value[i]+curr[j-weight[i]];
			}
			int exc=curr[j];
			curr[j]=max(inc,exc);
		}
	}
	return curr[capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	/*
	vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
	return memo(weight,value,n-1,maxWeight,dp);
	*/
	return tabuMoreOptimised(weight,value,n,maxWeight);
}
