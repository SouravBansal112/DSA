#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> arr(n,vector<int>(n,0));
        for(int i = 0; i < n; i++){
            string row;
            cin >> row;
            for(int j = 0; j < n; j++){
                arr[i][j] = row[j] - '0';
            }
        } 
        bool flag=true;  
        for(int i=0; i<n && flag ; i++){
            for(int j = 0; j<n ; j++){
                if(arr[i][j]==1){
                    if( (j+1<n && arr[i][j+1]==0) && (i+1<n && arr[i+1][j]==0)){
                        flag=false;
                        break;
                    }
                }
            }
        } 
        cout<< (flag? "YES":"NO") << endl;
    }
    return 0;
}