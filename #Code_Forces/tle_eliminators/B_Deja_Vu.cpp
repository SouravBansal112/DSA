#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<long long> a(n);
        vector<long long> b(q);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        for(int i=0; i<q; i++){
            cin>>b[i];
        }
        long long mini=LLONG_MAX;
        for(int i=0; i<q; i++){
            if(b[i]<mini){
                mini=b[i];
                for(int j =0 ; j<n ; j++){
                    if(a[j]%(1LL << b[i])==0){
                        a[j]+=(1LL << b[i]-1);
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            cout<<a[i]<<" ";
        }cout<<endl;
    }
}
