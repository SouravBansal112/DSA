#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

void getbits(vector<int> &v, vector<int> &bits){
    for(int i=0; i<v.size(); i++){
        int x=v[i];
        int cnt=0;
        while(x>0){
            if(x%2==1) bits[cnt]++;
            x/=2;
            cnt++;
        }
    }
}

void solve(){
    int n; 
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    vector<int> bits(31,0);
    getbits(v,bits);
    int ans=0;
    for(int i=0; i<31; i++){
        if(ans==0 && bits[i]>0) ans=bits[i];
        if(bits[i]>0){
            ans=__gcd(bits[i],ans);
        }
    }
    if(ans==0){
        for(int i=1; i<=n; i++) cout<<i<<" ";
        cout<<endl;
        return;
    }
    vector<int> vec;
    for(int i=1; i*i<=ans; i++){
        if(ans%i==0){
            vec.push_back(i);
            if(i!=ans/i) vec.push_back(ans/i);
        }
    }
    sort(vec.begin(),vec.end());
    for(int i=0; i<vec.size(); i++) cout<<vec[i]<<" ";
    cout<<endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}