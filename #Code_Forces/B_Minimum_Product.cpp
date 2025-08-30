#include<bits/stdc++.h>
using namespace std;

long long int product(int a,int b,int x,int y,int n){
    int dif=a-x;
    if(a-x<=n){
        n=n-(a-x);
        a=x;
    }
    else{
        a=a-n;
        n=0;
    }
    dif=b-y;
    if(b-y<=n){
        n=n-(b-y);
        b=y;
    }
    else{
        b=b-n;
        n=0;
    }
    return (long long)a*b;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,x,y,n;
        cin>>a>>b>>x>>y>>n;
        long long int ans1=product(a,b,x,y,n);
        long long int ans2=product(b,a,y,x,n);
        cout<<min(ans1,ans2)<<endl;
    }
    return 0;
}