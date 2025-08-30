#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    string s;
    cin>>s;
    for(int i=1 ; i<t; i++){
        if(s[i]<s[i-1]){
            cout<<"YES"<<endl<<i<<" "<<i+1<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}