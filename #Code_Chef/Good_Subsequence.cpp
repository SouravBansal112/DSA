#include<bits/stdc++.h>
using namespace std;

/*
for(int i=0; i<n ;i++){
  
}
*/
/*
vector<int> v(n);
*/


int main(){
    int t;
    cin>> t;
    while(t--){
        int n;
        cin>> n;
        vector<int> v(n);
        for(int i=0; i<n ;i++){
            cin>>v[i];
        }
        int ans= INT_MIN;
        
        for(int i=0; i<n; i++){
            int rem=v[i]%2;
            int temp=1;
            for(int j=i+1; j<n; j++){
                if(v[j]%2==rem){
                    continue;
                }
                else{
                    temp++;
                    rem=v[j]%2;
                }
            }
            ans=max(ans,temp);
        }

        cout<<ans<<endl;
    }
    return 0;
}