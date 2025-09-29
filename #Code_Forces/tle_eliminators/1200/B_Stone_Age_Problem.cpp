#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

void solve(){
    int n,m; 
    cin >>n>> m; 
    vector<ll> v(n);
    ll sum=0;
    for(int i=0; i<n; i++) {
        cin >> v[i];
        sum+=v[i];
    }
    vector<vector<ll>> q(m,vector<ll>(3));
    for(int i=0; i<m; i++){
        cin>>q[i][0];
        cin>>q[i][1];
        if(q[i][0]==1){
            cin>>q[i][2];
        }
    }
    unordered_set<ll> s;
    pair<bool,ll> p=make_pair(false,-1);
    for(int i=0; i<m; i++){
        if(q[i][0]==1){
            if(p.first){
                if(s.count(q[i][1])){
                    sum=sum-v[q[i][1]-1]+q[i][2];
                }else{
                    sum=sum-p.second+q[i][2];
                    s.insert(q[i][1]);
                }
            }
            else{
                sum=sum-v[q[i][1]-1]+q[i][2];
            }
            v[q[i][1]-1]=q[i][2];
            cout<<sum<<endl;
        }
        else{
            sum=q[i][1]*n;
            p.first=true;
            p.second=q[i][1];
            s.clear();
            cout<<sum<<endl;
        }
    }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}