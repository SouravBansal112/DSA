#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,k;
    cin>>n>>k;
    vector<long long> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    if(k == 0){
        if(arr[0] == 1){
            cout << -1;
        }
        else {
            cout << arr[0]-1;
        }
        return 0;
    }
    if((k < n && arr[k-1] == arr[k]) || k>n){
        cout << -1;
    } else {
        cout << arr[k-1];
    }
    return 0;
}