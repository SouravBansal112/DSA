#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

bool check(vector<pair<int,int>> &vec, int mid){
    ll init=mid;
    int i=0;
    int n=vec.size();
    while(i<n && init>=(ll)vec[i].first){
        init+=(ll)vec[i].second;
        i++;
    }
    if(i==n) return true;
    return false;
}



void solve(){
    int n; 
    cin >> n;
    vector<vector<int>> v(n);
    vector<pair<int,int>> vec;
    for(int i=0; i<n; i++){
        int k;
        cin>>k;
        v[i].resize(k);
        for(int j=0; j<k; j++){
            cin>>v[i][j];
        }
    }
    for(int i=0; i<n; i++){
        int mini=INT_MIN+1;
        for(int j=v[i].size()-1; j>=0; j--){
            if(v[i][j]<mini-1){
                mini--;
            }
            else{
                mini=v[i][j]+1;
            } 
        }
        vec.push_back(make_pair(mini,v[i].size()));
    }
    sort(vec.begin(),vec.end());
    int s=vec[0].first;
    int e=vec[vec.size()-1].first;
    int mid= s+(e-s)/2;
    int ans=INT_MAX;
    while(s<=e){
        mid=s+(e-s)/2;
        if(check(vec,mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    cout<<ans<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}