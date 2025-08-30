#include<bits/stdc++.h>
using namespace std;

void perm(int i, vector<int> &v, unordered_set<int> &s, int &n, bool &found, vector<int> &ans){
    if(i>=n){
        found=true;
        ans=v;
        return ;
    }
    int key=i-v[i];
    if(s.count(key)){
        return ;
    }
    s.insert(key);
    for(int j=i; j<n; j++){
        if(!found){
            swap(v[i],v[j]);
            perm(i+1,v,s,n,found,ans);
            swap(v[i],v[j]);
        }
    }
    s.erase(key);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
        }
        unordered_set<int> s;
        vector<int> ans;
        bool found=false;
        perm(0,v,s,n,found,ans);
        for(auto i:ans){
            cout<<i<<" ";
        }cout<<endl;
    }
    return 0;
}