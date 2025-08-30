#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==0){
            cout<<"NO"<<endl;
            continue;
        }
        if((n/2)%2!=0){
            cout<<"NO"<<endl;
            continue;
        }
        else{
            cout<<"YES"<<endl;
            int mid=n/2;
            vector<int> ans(n);
            for(int i=0; i<mid;i++){
                ans[i]=(i+1)*2;
                ans[mid+i]=ans[i]-1;
            }
            ans[n-1]=ans[mid-1]+mid-1;
            for(int i=0; i<n;i++){
                cout<<ans[i]<<" ";
            }cout<<endl;
        }   
    }
    return 0;
}