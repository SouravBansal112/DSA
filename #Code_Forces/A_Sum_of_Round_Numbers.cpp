#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<int> ans;
        int i=1;
        while(n!=0){
            int rem=(n%10);
            if(rem!=0){
                ans.push_back(rem*i);
            }
            n=n/10;
            i*=10;
        }
        cout<<ans.size()<<endl;
        for(int i=ans.size()-1; i>=0 ; i--){
            cout<<ans[i]<<" ";
        }cout<<endl;
    }
    return 0;
}