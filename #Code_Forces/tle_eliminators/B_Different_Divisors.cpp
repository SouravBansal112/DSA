#include<bits/stdc++.h>
using namespace std;

long long int nextprime(long long int n){
    while(n){
        bool prime=true;
        for(int i=2; i*i<=n; i++){
            if(n%i==0){
                prime=false;
            }
        }
        if(prime){
            return n;
        }
        n++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int d;
        cin>>d;
        long long int a=nextprime(1+d);
        long long int b=nextprime(a+d);
        long long int ans= a*a*a < a*b ? a*a*a : a*b ;
        cout<<ans<<endl;
    }
}