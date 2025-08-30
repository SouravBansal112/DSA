#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> &a, pair<int,int> &b){
    return a.first > b.first;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        string a,b;
        cin>>a>>b;
        if(a.size()>b.size()){
            string temp=a;
            a=b;
            b=temp;
        }
        int ans = INT_MIN;
        for(int i=0 ; i<a.size();i++ ){
            for(int j=0; j<b.size(); j++){
                if(a[i]==b[j]){
                    int cnt=1;
                    int k=i;
                    int l=j;
                    while(k+1<a.size() && l+1<b.size() && a[k+1]==b[l+1]){
                        cnt++;
                        k++;
                        l++;
                    }
                    ans=max(ans,cnt);
                }
            }
        }
        if(ans==INT_MIN){
            cout<<a.size()+b.size()<<endl;
        }
        else{
            cout<<a.size()+b.size()-2*ans<<endl;
        }
    }
}