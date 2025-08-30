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
        string s;
        cin>>s;
        int i=0;
        int j=s.length()-1;
        bool flag=true;
        while(i<j){
            if(s[i]!=s[j]){
                cout<<0<<endl;
                flag=false;
                break;
            }
        }
        if(!flag){
            continue;
        }
        


    }
    return 0;
}