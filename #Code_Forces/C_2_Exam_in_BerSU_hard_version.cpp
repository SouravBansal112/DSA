#include<bits/stdc++.h>
using namespace std;

struct cmp {
    bool operator()(const int &a, const int &b) const {
        return a > b;
    }
};

int main(){
    int n,M;
    cin>>n>>M;
    vector<int> v(n);
    vector<int> ans(n,0);
    for(int i=0; i< n ; i++){
        cin>>v[i];
    }
    int sum=0;
    map<int,int,cmp> m;
    for(int i =0 ; i<n ; i++){
        sum+=v[i];
        int d=sum-M;
        if(d>0){
            for(auto j:m){
                int x= j.first*j.second;
                if(d<=x){
                    ans[i]+=(d+j.first-1)/j.first;
                    break;
                }
                d-=x;
                ans[i]+=j.second;
            }
        }
        if(m.count(v[i])){
            m[v[i]]++;
        }
        else{
            m.insert(make_pair(v[i],1));
        }
    }
    for(int i=0; i< n ; i++){
        cout<<ans[i]<<" ";
    }   
    return 0;
}