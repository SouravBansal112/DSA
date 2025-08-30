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
        string v;
        cin>>v;
        set<char> ma;
        set<char> mb;
        vector<int> prefa(n);
        vector<int> prefb(n);
        int d1=0;
        int d2=0;
        for(int i=0 ; i<n; i++){
            if(!ma.count(v[i])){
                ma.insert(v[i]);
                d1++;
            }
            prefa[i]=d1;
            if(!mb.count(v[n-i-1])){
                mb.insert(v[n-i-1]);
                d2++;
            }
            prefb[n-i-1]=d2;
        }
        int ans=INT_MIN;
        for(int i=0; i<n-1; i++){
            ans=max(ans, prefa[i]+prefb[i+1]);
        }
        cout<<ans<<endl;
    }
    return 0;
}