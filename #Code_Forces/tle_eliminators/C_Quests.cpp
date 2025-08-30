#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        vector<int> b(n);
        vector<int> pref(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        for(int i=0; i<n; i++){
            cin>>b[i];
        }
        int maxi=b[0];
        pref[0]=a[0];
        int ans=pref[0]+(k-1)*maxi;
        for(int i=1; i<n && k-i-1 >=0 ; i++){
            pref[i]=a[i]+pref[i-1];
            maxi=max(maxi,b[i]);
            ans=max(ans,pref[i]+(k-i-1)*maxi);
        }
        cout<<ans<<endl;
    }
}