#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007
typedef       long long     ll;

ll gcd(ll a, ll b){
    while(b!=0){
        int temp=b;
        b=a%b;
        a=temp;
    }
    return (ll)a;
}

void solve(){
    int n; 
    cin >> n; 
    string s;
    cin>>s;
    int m;
    cin>>m;
    ll pos=0;
    ll neg=0;
    for(int i=0; i<n; i++){
        if(s[i]=='+') pos++;
        else neg++;
    }
    for(int i=0; i<m; i++){
        ll x,y;
        cin>>x>>y;
        if(neg==pos){
            cout<<"YES"<<endl;
            continue;
        }
        ll lcm= (x*y)/gcd(x,y);
        ll a= lcm/x;
        ll b= lcm/y;
        ll difference=abs(pos-neg);
        ll reduction=abs(a-b);
        //if(pos%a==neg-(b*(pos/a)) || pos%b==neg-(a*(pos/b)) || neg%a==pos-(b*(neg/a)) || neg%b==pos-(a*(neg/b))) cout<<"YES"<<endl;
        if(reduction!=0 && difference%reduction==0){
            ll p=difference/reduction;
            if(p*(a+b)<=n){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}