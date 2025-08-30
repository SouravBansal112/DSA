#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n%2==0){
            cout<<n/2<<" "<<n/2<<endl;
            continue;
        }
        int a=1;
        int b=n-1;
        pair<int,int> lcm=make_pair(INT_MAX,-1);
        for(int i=2 ; i*i<=n; i++){
            if((n-i)%i==0){
                a=n/i;
                b=n-a;
                break;
            }
        }
        cout<<a<<" "<<b<<endl;
    }
    return 0;
}
