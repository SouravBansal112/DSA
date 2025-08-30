#include<bits/stdc++.h>
using namespace std;

/*
vector<int> v(n);
for(int i=0 ; i<n ; i++){
    cin>>v[i];
}
*/
/*
for(int i=0 ; i<n ; i++){

}
*/

bool cmp(pair<int,int> &a,pair<int,int> &b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    return a.first > b.first;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<pair<int,int>> v;
        for(int i=0 ; i<n ; i++){
            int x;
            cin>>x;
            if(x%k==0){
                v.push_back({k,i+1});
            }
            else{
                v.push_back({x%k,i+1});
            }
        }
        sort(v.begin(),v.end(),cmp);
        for(auto i:v){
            cout<<i.second<<" ";
        }     
        cout<<endl;
    }
}