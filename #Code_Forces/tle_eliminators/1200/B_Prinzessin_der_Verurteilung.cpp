#include<bits/stdc++.h>
using namespace std;
#define       MOD           1000000007;
typedef       long long     ll;

void stadd(string &s){
  int j=s.length()-1;
  while(j>=0){
    if(s[j]=='z'){ 
      s[j]='a';
      j--;
    }
    else{
      s[j]++;
      return;
    }
  }
}

void solve(){
    int n; 
    cin >> n; 
    string s;
    cin>>s;
    int k=0;
    while(k<3){
      int i=0;
      set<string> st;
      while(i<n-k){
        st.insert(s.substr(i,k+1));
        i++;
      }
      string x(k+1,'a');
      for(int i=0; i<pow(26,k+1); i++){
        if(!st.count(x)){
          cout<<x<<endl;
          return;
        }
        stadd(x);
      }
      k++;
    }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
  return 0;
}