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
        set<long long int> s;
        bool flag=true;
        for(int i=0; i<n; i++){
            long long int x;
            cin>>x;
            if(s.count(x)){
                flag=false;
            }
            s.insert(x);
        }
        if(flag){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
}