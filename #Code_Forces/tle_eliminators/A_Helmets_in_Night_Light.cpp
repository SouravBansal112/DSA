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
        int n, p;
        cin>>n>>p;
        vector<pair<int,int>> v;
        for(int i=0 ; i<n; i++){
            int x;
            cin>>x;
            v.push_back({x,0});
        }
        for(int i=0 ; i<n; i++){
            int x;
            cin>>x;
            v[i].second=x;
        }
        sort(v.begin(),v.end(),cmp);
        queue<pair<int,int>> q;
        q.push(v[0]);
        int i=1;
        long long int ans = p;
        
        while(i<n){
            long long int cnt=q.front().first;
            long long int cost=q.front().second;
            q.pop();
            if(cost>p){
                ans+=(long long)p*(n-i);
                break;
            }
            if(cnt==0){
                if(q.empty()){
                    q.push(v[i]);
                    ans+=p;
                    i++;
                }
            }
            while(cnt>0 && i<n){
                q.push(v[i]);
                i++;
                cnt--;
                ans+=cost;
            }
        }
        cout<<ans<<endl;
    }
}