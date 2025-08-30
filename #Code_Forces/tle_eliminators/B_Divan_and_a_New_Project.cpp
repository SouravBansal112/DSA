#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> &a, pair<int,int> &b){
    return a.first > b.first;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long int ans=0;
        vector<pair<int,int>> v(n);
        for(int i=0 ; i<n;i++ ){
            cin>>v[i].first;
            v[i].second=i;
        }
        sort(v.begin(),v.end(),cmp);
        vector<int> a(n+1);
        a[0]=2;
        for(int i=0; i<n; i++){
            int dist=(i/2+1);
            ans+=(long long)v[i].first*2*dist;
            int index= i%2==0? a[0]+dist : a[0]-dist;
            a[v[i].second+1]=index;
        }
        cout<<ans<<endl;
        for(int i=0; i<=n; i++){
            cout<<a[i]<<" ";
        }cout<<endl;
    }
}