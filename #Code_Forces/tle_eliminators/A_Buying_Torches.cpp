#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        long long int x,y,k;
        cin>>x>>y>>k;
        long long int ans=k;
        long long int sticks=k+y*k;
        ans+= (sticks)/(x-1);

        if(sticks%(x-1)!=0 && sticks%(x-1)!=1){ans++;}
        if(x==2){ans--;}
        cout<<ans<<endl;
    }
}