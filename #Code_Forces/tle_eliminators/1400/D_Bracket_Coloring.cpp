#include <bits/stdc++.h>
using namespace std;
 void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    stack<int> st;
    vector<int> ans(n,2);
    for(int i=0; i<n; i++){
        if(s[i]=='('){
            st.push(i);
            continue;
        }
        if(s[i]==')' && !st.empty() && s[st.top()]=='('){
            ans[i]=1;
            ans[st.top()]=1;
            st.pop();
            continue;
        }
    }
    while(!st.empty()) st.pop();
    stack<int> stk;
    int cnt=0;
    bool rev=true;
    for(int i=n-1; i>=0; i--){
        if(ans[i]==2){
            cnt++;
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')' && !st.empty() && s[st.top()]=='('){
                st.pop();
            }
            else{
                cout<<-1<<endl;
                return;
            }  
        }
        if(s[i]=='('){
            stk.push(i);
        }
        else if(s[i]==')' && !stk.empty() && s[stk.top()]=='('){
            stk.pop();
            continue;
        }
        else{
            rev=false;
        }
    }
    if(!st.empty()){
        cout<<-1<<endl; return;
    }
    if(cnt==n || cnt==0 || (rev && stk.empty())){
        cout<<1<<endl;
        for(int i=0; i<n; i++) cout<<1<<" ";
        cout<<endl;
        return;
    }
    cout<<2<<endl;
    for(int i=0; i<n; i++) cout<<ans[i]<<" ";
    cout<<endl;
 }
 
int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }
 
    return 0;
}