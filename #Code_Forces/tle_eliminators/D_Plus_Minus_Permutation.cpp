#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    while(a!=0){
        int temp=a;
        a=b%a;
        b=temp;
    }
    return b;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,x,y;
        cin>>n>>x>>y;
        long long l=x*y/gcd(x,y);
        long long common=n/l;
        long long maxi=n/x -common;
        long long mini=n/y -common;
        long long ans=0;
        ans+= (maxi)*(2*(n-maxi+1) +maxi-1)/2;
        ans-= (mini)*(2+mini-1)/2;
        cout<<ans<<endl;
    }
}
