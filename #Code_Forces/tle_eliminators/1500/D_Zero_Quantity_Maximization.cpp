#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;
 
int gcd(int a,int b){
    while(b!=0){
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
 
void solve(){
    int n; 
    cin >> n; 
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];
    map<pair<int,int>,int> cnt;
    int ans=0;
    for(int i=0; i<n; i++) {
        if(a[i]==0 && b[i]==0) {ans++; continue;}
        else if(a[i]==0) continue;
        int g= gcd(abs(a[i]),abs(b[i]));
        int den= a[i]/g;
        int num= -b[i]/g;
        if (num < 0) { num *= -1; den *= -1; }
        else if(num==0 && den<0) den*=-1;
        cnt[{num,den}]++;
    }
    int maxi=0;
    for(auto i:cnt) maxi=max(maxi,i.second);
    cout<<maxi+ans<<endl;
}
 
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}