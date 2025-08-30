#include<bits/stdc++.h>
using namespace std;

void solve(int i,int num,int sum,int maxi, int mini, int &ans,int& n, int& l, int &r, int &x, vector<int> &v){
    if(i==n){
        if(num>=2 && l<=sum && sum<=r && x<=maxi-mini){
            ans++;
        }
        return;
    }
    solve(i+1,num,sum,maxi,mini,ans,n,l,r,x,v);
    num++;
    maxi=max(maxi,v[i]);
    mini=min(mini,v[i]);
    sum+=v[i];
    solve(i+1,num,sum,maxi,mini,ans,n,l,r,x,v);
}

int main(){
    int n,l,r,x;
    cin>>n>>l>>r>>x;
    vector<int> v(n,0);
    for(int i=0; i<n ; i++){
        cin>>v[i];
    }
    int ans=0;
    solve(0,0,0,INT_MIN,INT_MAX,ans,n,l,r,x,v);
    cout<<ans;
    return 0;
}
