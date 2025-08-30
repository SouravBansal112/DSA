#include <bits/stdc++.h> 
using namespace std;
/*You are given an array of distinct integers and you have to tell how many different ways of selecting the elements from the array are there such that the sum of chosen elements is equal to the target number tar.
Note: Two ways are considered the same if for every index the contents of both the ways are equal example way1=[1,2,3,1] and way2= [1,2,3,1] both way1 and way 2 are the same.
But if way1 =[1,2,3,4] and way2= [4,3,2,1] then both ways are different.*/
int tabu(vector<int> &num, int tar){
    vector<int> dp(tar+1,0);
    dp[0]=1;
    for(int i=1 ; i<= tar; i++){
        for(auto j:num){
            if(i-j>=0){
                dp[i]= dp[i]+ dp[i-j];
            }
        }
    }
    return dp[tar];
}

int findWays(vector<int> &num, int tar)
{
    tabu(num,tar);
}


