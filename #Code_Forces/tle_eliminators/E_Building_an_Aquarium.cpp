#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<ll> v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        vector<ll> pref(n);
        pref[0]=v[0];
        for(int i=1; i<n ; i++){
            pref[i]=pref[i-1]+v[i];
        }
        ll s=v[0];
        ll e=v[n-1];
        if(s==e){
            cout<<x/n + s<<endl;
            continue;
        }
        ll ans=INT_MIN;
        while(s<=e){
            ll mid=s+(e-s)/2;
            int idx = upper_bound(v.begin(), v.end(), mid) - v.begin();
            ll sum=0;
            if(idx>0){
                sum=mid*idx - pref[idx-1];
            }
            
            if(sum<=x){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        if(ans==v[n-1]){
            ll rem = x- (ans*n-pref[n-1]);
            ans+=rem/n;
        }
        cout<<ans<<endl;
    }
}
