#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        long long int a,b;
        cin>>a>>b;
        if(a==b){
            cout<<0<<endl;
            continue;
        }
        if(a<b) swap(a,b);
        bool flag=true;
        int shift=0;
        if(a%b!=0){
            cout<<-1<<endl;
            continue;
        }
        long long int r=a/b;
        while(r>1){
            if(a%2==1){
                cout<<-1<<endl;
                flag=false;
                break;
            }
            if(r%8==0){
                a=a/8;
                r=r/8;
                shift++;
            }
            else if(r%4==0){
                a=a/4;
                r=r/4;
                shift++;
            }
            else if(r%2==0){
                a=a/2;
                r=r/2;
                shift++;
            }
            else{
                cout<<-1<<endl;
                flag=false;
                break;
            }
        }
        if(flag){
            cout<<shift<<endl;
        }   
    }
}