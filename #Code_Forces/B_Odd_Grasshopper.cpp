 #include<bits/stdc++.h>
 using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int x,n;
        cin>>x>>n;
        int d=(n/4)*4+1;
        int k=n%4;
        if(x % 2 == 0){
            if(k==1){
                x=x-d;
            }
            else if(k==2){
                x=x+d;
            }
            else if(k==3){
                x=x+4*d;
            }
        }
        else{
            if(k==1){
                x=x+d;
            }
            else if(k==2){
                x=x-d;
            }
            else if(k==3){
                x=x-4*d;
            }
        }
        cout<<x<<endl; 
    }
    return 0;
}