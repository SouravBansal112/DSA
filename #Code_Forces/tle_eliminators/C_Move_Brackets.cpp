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
        string s;
        cin>>s;
        stack<char> stk;
        for(int i=0; i<n; i++){
            if(s[i]==')' && !stk.empty() && stk.top()=='('){
                stk.pop();
            }
            else{
                stk.push(s[i]);
            }
        }
        cout<<stk.size()/2<<endl;
    }
}