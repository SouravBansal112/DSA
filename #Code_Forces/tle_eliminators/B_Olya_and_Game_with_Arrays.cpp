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

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> v(n);
        long long int sum=0;
        int _min2=INT_MAX;
        int _min=INT_MAX;

        for(int i=0; i<n; i++){
            int m;
            cin>>m;
            int mini=INT_MAX;
            for(int j=0; j<m; j++){
                int x;
                cin>>x;
                v[i].push_back(x);
                mini=min(mini,x);
            }
            _min=min(_min,mini);
        }
        for(int i=0; i<n; i++){
            sort(v[i].begin(),v[i].end());
            _min2=min(_min2,v[i][1]);
            sum+=v[i][1];
        }
        long long ans=sum+_min-_min2;
        cout<<ans<<endl;
    }
}