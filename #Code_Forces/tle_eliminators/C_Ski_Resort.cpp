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
        int n,k,q;
        cin>>n>>k>>q;
        vector<int> v(n);

        for(int i=0 ; i<n ; i++){
            cin>>v[i];
        }
        vector<int> seg;
        int cnt=0;
        for(int i=0 ; i<n ; i++){
            if(v[i]<=q){
                cnt++;
            }
            else if(cnt!=0){
                //cout<<"count "<<cnt<<endl;
                if(cnt>=k){
                    seg.push_back(cnt);
                }
                cnt=0;
            }
        }
        if(cnt!=0 && cnt>=k){seg.push_back(cnt);}
        long long int ans=0;
        for(auto i:seg){
            long long int x=i-k+1;
            ans+= x*(x+1)/2;
        }
        cout<<ans<<endl;
    }
}