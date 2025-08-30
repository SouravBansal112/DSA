#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        bool zero=false;
        int neg=0;
        int sum=0;
        int mini=INT_MAX;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int x;
                cin>>x;
                if(x<0){
                    neg++;
                    x=abs(x);
                }
                if(x==0){
                    zero=true;
                }
                mini=min(mini,x);
                sum+=x;
            }
        }
        if(zero || neg%2==0){
            cout<<sum<<endl;
        }
        else{
            cout<<sum-2*mini<<endl;
        }
    }
}