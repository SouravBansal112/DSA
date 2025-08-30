#include<bits/stdc++.h>
using namespace std;

/*
for(int i=0; i<n ;i++){
  
}
*/
/*
vector<int> v(n);
*/


int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    string s;
    for(int i=0; i<n ; i++){
      if(i%3==0){
        s.push_back('a');
      }else if(i%3==1){
        s.push_back('c');
      }else{
        s.push_back('b');
      }
    }
    cout<<s<<endl;  
  }
}