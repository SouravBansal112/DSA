#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
#define       pb            push_back
typedef       long long     ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

void solve(){
    int n,k1,k2; 
    cin >> n>>k1>>k2; 
    int k=k1+k2;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];
    priority_queue<int> pq;
    for(int i=0; i<n; i++) pq.push(abs(a[i]-b[i]));
    while(k>0){
        int fr=pq.top();
        pq.pop(); fr--;
        pq.push(abs(fr));
        k--;
    }
    ll ans=0;
    while(!pq.empty()){
        int fr=pq.top();
        pq.pop();
        ans+=(ll)fr*fr;
    }cout<<ans<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}