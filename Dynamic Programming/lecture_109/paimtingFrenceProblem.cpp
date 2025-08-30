#include <bits/stdc++.h>
using namespace std;

int memo(int n, int k,int ways){
    if(n==0){
        return ways;
    }
    int ans;
    if(ways==1){
        ans=memo(n-1,k,k-1);
    }
    else{
        ans=ways*(memo(n-1,k,k-1)+memo(n-1,k,1));
    }
    return ans;
}
int numberOfWays(int n, int k) {
    return memo(n,k,k);
}

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int memo(int n,int k){
    if(n==1){
        return k;
    }
    if(n==2){
        return k+k*(k-1);
    }

    int ans=(k-1)*(memo(n-1,k)+memo(n-2,k));
 
    return ans;
}
int numberOfWays(int n, int k) {
    return memo(n,k);
}






