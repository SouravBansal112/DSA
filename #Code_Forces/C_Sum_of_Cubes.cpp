#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long int n;
        cin>>n;
        map<long long int,int> m;
        bool flag=true;
        for (long long int i=1 ; i*i*i<=n ; i++){
            m.insert(make_pair(i*i*i,1));
        }
        for(long long int i=1; i*i*i<n ; i++){
            long long int d=n-i*i*i;
            if(m.count(d)){
                cout<<"YES"<<endl;
                flag=false;
                break;
            }
        }
        if(flag){
            cout<<"NO"<<endl;
        }      
    }
    return 0;
}
