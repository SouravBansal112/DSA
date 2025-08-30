#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        char arr[8][8];
        bool stop=false;
        for(int i=0; i<8; i++){
            for(int j= 0 ; j<8 ; j++){
                cin>>arr[i][j];
            }
        }
        for(int i=1; i<7 && !stop ; i++){
            for(int j=1 ; j<7 ; j++){
                if(arr[i-1][j-1]=='#' && arr[i-1][j+1]=='#' && arr[i][j]=='#'){
                    cout<<i+1<<" "<<j+1<<endl;
                    stop=true;
                    break;
                }
            }
        }
    }
    return 0;
}