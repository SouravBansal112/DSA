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
        string a;
        for(int i=0 ; i<n ; i++){
            char c;
            cin>>c;
            a.push_back(c);
        }
        int m;
        cin>>m;
        string b;
        for(int i=0 ; i<m ; i++){
            char c;
            cin>>c;
            b.push_back(c);
        }
        string d;
        for(int i=0 ; i<m ; i++){
            char c;
            cin>>c;
            d.push_back(c);
        }
        string ans;
        for(int i=0; i<m ;i++){
            if(d[i]=='D'){
                a.push_back(b[i]);
            }
        }
        for(int i=m-1; i>=0 ;i--){
            if(d[i]=='V'){
                ans.push_back(b[i]);
            }
        }
        ans = ans+a;
        cout<<ans<<endl;
    }
    return 0;
}
