#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> &a, pair<int,int> &b){
    return a.first > b.first;
}

int msb(int n){
    int cnt=0;
    while(n!=0){
        n=n/2;
        cnt++;
    }
    return cnt-1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int m=msb(n-1);
        int s=pow(2,m)-1;
        while(s>=0){
            cout<<s<<" ";
            s--;
        }
        s=pow(2,m);
        while(s<n){
            cout<<s<<" ";
            s++;
        }cout<<endl;
    }
}