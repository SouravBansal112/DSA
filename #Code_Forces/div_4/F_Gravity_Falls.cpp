#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    int maxi = 0;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        maxi = max(maxi, k);
        v[i].resize(k);
        for (int j = 0; j < k; j++) cin >> v[i][j];
    }
    int x = 0;
    for (int i = 1; i < n; i++) {
        bool flag=false;
        int lim = min(v[i].size(), v[x].size());
        for (int t = 0; t < lim; t++) {
            if (v[i][t] != v[x][t]) {
                flag=true;
                x= v[i][t]<v[x][t]? i:x;
                break;
            }
        }
        if(!flag)x= v[i].size()<=v[x].size()? i:x;
    }
    vector<int> mins(maxi, INT_MAX);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            mins[j] = min(mins[j], v[i][j]);
        }
    }

    for (int val : v[x]) cout << val <<" ";

    for (int j = v[x].size(); j < maxi; j++) {
        cout << mins[j] <<" ";
    }
    cout <<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}