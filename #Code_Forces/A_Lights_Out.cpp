#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> arr(3,vector<int>(3));
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>arr[i][j];
        }
    }
    vector<vector<bool>> ans(3,vector<bool>(3,1));
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            bool toggle=arr[i][j]%2;
            if(toggle){
                if(i-1 >= 0){
                    ans[i-1][j]=(!ans[i-1][j]);
                }
                if(j-1 >= 0){
                    ans[i][j-1]=(!ans[i][j-1]);
                }
                if(i+1<3){
                    ans[i+1][j]=(!ans[i+1][j]);
                }
                if(j+1 <3){
                    ans[i][j+1]=(!ans[i][j+1]);
                }
                ans[i][j]=(!ans[i][j]);
            }
        }
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<ans[i][j];
        }cout<<endl;
    }
    return 0;
}