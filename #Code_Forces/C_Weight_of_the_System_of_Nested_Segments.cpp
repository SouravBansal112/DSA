#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,pair<int,int>>& a, pair<int,pair<int,int>>& b){
    return a.second.second < b.second.second;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<pair<int,pair<int,int>>> s;
        for(int i= 0; i<m ; i++){
            int x,y;
            cin>>x>>y;
            s.push_back({i,{x,y}});
        }
        int wt=0;
        vector<pair<int,pair<int,int>>> v;
        sort(s.begin(),s.end(),cmp);
        for(int i=0; i<2*n; i++){
            int x=s[i].first;
            int y=s[i].second.first;
            int z=s[i].second.second;
            wt+=z;
            v.push_back({x,{z,y}});
        }
        sort(v.begin(),v.end(),cmp);
        int i=0;
        int j=v.size()-1;
        cout<<wt<<endl;
        while(i<=j){
            cout << v[i].first+1 << " " << v[j].first+1 << "\n";
            i++;
            j--;
        }
        cout<<endl;
    }
    return 0;
}

