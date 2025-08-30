#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n,0);
        vector<int> b(n,0);
        for(int i=0 ; i<n ; i++){
            cin>>a[i];
        }
        for(int i=0 ; i<n ; i++){
            cin>>b[i];
        }
        bool type0=false;
        bool type1=false;
        bool sorted=true;
        for(int i=0 ; i<n ; i++){
            if(i+1<n && a[i]>a[i+1]){
                sorted=false;
            }
            if(b[i]==1){
                type1=true;
            }
            else{
                type0=true;
            }
        }
        if(type1 && type0){
            cout<<"Yes"<<endl;
            continue;
        }
        if(sorted){
            cout<<"Yes"<<endl;
            continue;
        }
        cout<<"No"<<endl;        
    }
    return 0;
}