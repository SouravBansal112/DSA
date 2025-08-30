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
        map<int,int> m;
        int ans=n;
        for(int i=0; i<n; i++){
            if(m.count(s[i])){
                ans+=i-m[s[i]]-1;
            }
            m[s[i]]=i;
        }
        for(auto i:m){
            ans+=n-i.second-1;
        }
        cout<<ans<<endl;
    }
}