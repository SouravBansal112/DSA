#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> &a, pair<int,int> &b){
    if(a.second==b.second){
        return a.first > b.first;
    }
    return a.second < b.second;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        char c;
        cin>>n>>c;
        string s;
        cin>>s;
        int time=0;
        bool fc=false;
        bool fg=false;
        int prev=0;
        int ans=INT_MIN;
        for(int i=0 ; i<n; i++){
            if(!fg && s[i]=='g'){
                prev=i+1;
                fg=true;
            }
            if(fc){
                time++;
            }
            else if(!fc && s[i]==c){
                fc=true;
            }
            if(fc && s[i]=='g'){
                ans = max(ans,time);
                fc=false;
                time=0;
            }
            if(i==n-1 && fc){
                ans=max(ans, time+prev);
            }
        }
        cout<<ans<<endl;
    }
}