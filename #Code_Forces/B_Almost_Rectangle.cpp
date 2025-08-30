#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<char>> arr(n,vector<char>(n));
        vector<int> ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<n ; j++){
                cin>>arr[i][j];
                if(arr[i][j]=='*'){
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        if(ans[0]==ans[2]){
            if(ans[0]>0){
                ans[0]=ans[2]=0;
            }
            else{
                ans[0]=ans[2]=n-1;
            }
        }
        if(ans[1]==ans[3]){
            if(ans[1]>0){
                ans[1]=ans[3]=0;
            }
            else{
                ans[1]=ans[3]=n-1;
            }
        }
        else{
            int a=ans[0];
            ans[0]=ans[2];
            ans[2]=a;
        }
        arr[ans[0]][ans[1]]='*';
        arr[ans[2]][ans[3]]='*';
        for(int i=0; i<n; i++){
            for(int j=0; j<n ; j++){
                cout<<arr[i][j];
            }cout<<endl;
        }
    }
}

