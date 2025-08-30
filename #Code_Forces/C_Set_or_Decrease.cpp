#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin>>t;
    while(t--){
        long long int n,k;
        cin>>n>>k;
        vector<long long int> v(n);
        for(long long int i=0 ; i<n ; i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        vector<long long int> pref(n);
        pref[0]=v[0];
        for (long long int i = 1; i < n; i++){
            pref[i] = pref[i-1] + v[i];
        } 
        if(pref[n-1]<=k){
            cout<<0<<endl;
            continue;
        }
        long long int ans=9223372036854775807LL;
        for(long long int y=0; y<n ; y++){
            long long int dif=pref[n-y-1]+y*v[0] -k ;
            long long int m=0;
            long long int x = max(m,(dif+y)/(y+1));
            ans= min(ans,x+y);
        }
        cout<<ans<<endl;
    }
    return 0;
}

/*
1
3 5
4 4 4
*/
/*
4
1 10
20
2 69
6 9
7 8
1 2 1 3 1 2 1
10 1
1 2 3 1 2 6 1 6 8 10
*/
/*
10
0
2
7
*/