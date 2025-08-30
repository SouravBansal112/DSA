#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int n,k;
    cin>>n>>k;
    long long int mid= n%2==0? n/2 : n/2 +1 ;
    if(k<=mid){
        cout<< (k)*2 -1;
        return 0; 
    } 
    else{
        cout<< (k-mid)*2;
        return 0;
    }
}