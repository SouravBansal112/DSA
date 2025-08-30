#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    vector<int> a(t);
    vector<int> b(t);
    for(int i=0 ; i<t ; i++){
        cin>>a[i];
    }
    for(int i=0 ; i<t ; i++){
        cin>>b[i];
    }
    vector<bool> visited(t+1,false);
    int i=0;
    int j=0;
    int ans=0;
    while(i<t && j<t){
        if(a[i]==b[j]){
            visited[b[j]]=true;
            i++;
            j++;
        }
        else if(!visited[a[i]]){
            visited[b[j]]=true;
            ans++;
            j++;
        }
        else{
            i++;
        }
    }
    cout<<ans;
    return 0;
}