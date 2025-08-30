#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        sort(s.begin(),s.end());
        
        if(s[k-1]!=s[0]){
            cout<<s[k-1]<<endl;
            continue;
        }
        /*
        if (s[k] != s[n-1]) {
            cout << s[0] << s.substr(k) << "\n";
        }
        else {
            cout << s[0];
            int remaining = (n - k + k - 1) / k; // ceil((n-k)/k)
            cout << string(remaining, s[k]) << "\n";
        }*/
    }
    return 0;
}
