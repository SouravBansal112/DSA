#include<bits/stdc++.h>
using namespace std;

/*
vector<int> v(n);
for(int i=0 ; i<n ; i++){
    cin>>v[i];
}
*/
/*
for(int i=0 ; i<n ; i++){

}
*/

int dropdmg(vector<int> &v,int bottom, int top,int dmg){
    if(top<bottom){
        return 0;
    }
    if(v[bottom]-dmg<=0){
        if(v[bottom]-dmg<0){
            dmg=v[bottom];
        }
        return dmg+dropdmg(v,bottom+1,top,1);
    }
    else{
        return dmg;
    }
}

int sim(vector<int> &v, int &bottom, int &top){
    int mini=v[bottom];
    int index=bottom;
    for(int i=bottom; i<top; i++){
        int dmg=i-bottom+1;
        dmg=dropdmg(v,i+1,top,dmg);
        if(v[i]-dmg < mini){
            mini=v[i]-dmg;
            index=i;
        }
    }
    return index;
}

void drop(vector<int> &v,int bottom, int top, int &ans, int dmg){
    if(top<bottom){
        return;
    }
    v[bottom]-=dmg;
    // if(bottom+1==top){
    //     ans+=v[bottom];
    //     drop(v,top,top,ans,1);
    //     return;
    // }
    if(v[bottom]<=0){
        drop(v,bottom+1,top,ans,1);
        return ;
    }
    int mini=sim(v,bottom,top);
    ans+=v[mini];
    v[mini]=0;
    int d=(mini-bottom+1);
    drop(v,mini+1,top,ans,d);
    drop(v,bottom,mini-1,ans,0);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--){
      int n;
      cin>>n;
      vector<int> v(n);
      for(int i=0; i<n; i++){
        cin>>v[i];
      }
      int ans=0;
      drop(v,0,n-1,ans,0);
      cout<<ans<<endl;
  }
}










