#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        if(n<=k){
            cout<<1<<endl;
            continue;
        }
        long long int ans=1;
        int s=sqrt(n);
        int lim= min(k,s);
        for(long long int i=1; i<=lim ; i++){
            if(n%i==0){
                if(i<=k){
                    ans=max(ans,i);
                }
                if(n/i <=k ){
                    ans=max(ans,n/i);
                }
            }
        }   
        cout<<n/ans<<endl;
    }
    return 0;
}
