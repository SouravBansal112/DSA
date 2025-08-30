#include<bits/stdc++.h>
using namespace std;

pair<long long int,long long int> segment(int &i,vector<long long int> &t,vector<long long int> &h){
    return make_pair(t[i]-h[i],t[i]);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long int> t(n);
        vector<long long int> h(n);
        for(int i=0 ; i< n; i++){
            cin>>t[i];
        }
        for(int i=0 ; i< n; i++){
            cin>>h[i];
        }
        vector<pair<long long int,long long int>> s;
        long long int mana=0;
        for(int i=0 ; i< n; i++){
            pair<long long int,long long int> seg=segment(i,t,h);
            s.push_back(seg);
            int n=s.size()-1;
            while(n>0 && s[n-1].second > s[n].first){
                if(s[n-1].first > s[n].first){
                    s[n-1]= s[n];
                    s.pop_back();
                    n--;
                }
                else{
                    s[n-1].second = s[n].second;
                    s.pop_back();
                    n--;
                }
            }
        }
        for(auto i:s){
            long long int n= (i.second-i.first);
            mana+= n*(n+1)/2;
        }
        cout<<mana<<endl;
    }
    return 0;
}