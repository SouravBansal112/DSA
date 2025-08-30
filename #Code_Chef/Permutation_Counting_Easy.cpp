#include<bits/stdc++.h>
using namespace std;


int main(){
  int t;
  cin>>t;
  while(t--){
    int n,k;
    cin>>n>>k;
    int temp=1;
    int tot=1;
    for(int i=1; i<=n ; i++){
        tot=tot*i;
        if(i<=n-2){
            temp=temp*i;
        }
    }
    int exc=0;
    for(int i=1; i<n; i++){
        for(int j=i+1; j<=n; j++){
            if((i+j)%3==0){
                exc++;
            }
        }
    }
    int ans= tot - (exc*temp*(n-1)*2);
    ans=ans%998244353;
    cout<<ans<<endl;
  }
}






