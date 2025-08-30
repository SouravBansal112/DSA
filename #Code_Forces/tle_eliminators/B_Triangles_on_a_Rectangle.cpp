#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        long long int ans=INT_MIN;
        vector<pair<int,int>> base(4);
        for(int i=0 ; i<4;i++ ){
            int k;
            cin>>k;
            vector<int> v(k);
            for(int j=0; j<k; j++){
                cin>>v[j];
            }
            base[i].first=v[k-1]-v[0];
            if(i<2){
                base[i].second=y;
            }
            else{
                base[i].second=x;
            }
            ans=max(ans, (long long)base[i].first*base[i].second);
        }
        cout<<ans<<endl;
    }
}