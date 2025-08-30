#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> &a, pair<int,int> &b){
    if(a.second==b.second){
        return a.first > b.first;
    }
    return a.second < b.second;
}

void len(vector<int> &v, map<int,int> &m, set<int> &s,int &n){
    int cnt = 1;
    m[v[0]]=cnt;
    if(!s.count(v[0])){
        s.insert(v[0]);
    }
    for(int i=1; i<n; i++){
        if(!s.count(v[i])){
            s.insert(v[i]);
        }
        if(v[i]==v[i-1]){
            cnt++;
        }
        else{
            if(m.count(v[i-1])){
                m[v[i-1]]=max(m[v[i-1]],cnt);
            }
            else{
                m[v[i-1]]=cnt;
            }
            cnt=1;
        }
    }
    if(m.count(v[n-1])){
        m[v[n-1]]=max(m[v[n-1]],cnt);
    }
    else{
        m[v[n-1]]=cnt;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        for(int i=0 ; i<n; i++){
            cin>>a[i];
        }
        for(int i=0 ; i<n; i++){
            cin>>b[i];
        }
        map<int,int> ma;
        map<int,int> mb;
        set<int> s;
        len(a,ma,s,n);
        len(b,mb,s,n);
        int ans=INT_MIN;
        for(auto i:s){
            if(ma.count(i) && mb.count(i)){
                ans=max(ma[i]+mb[i],ans);
            }
            else if(ma.count(i)){
                ans=max(ma[i],ans);
            }
            else{
                ans=max(mb[i],ans);
            }
        }
        cout<<ans<<endl;
    }
}