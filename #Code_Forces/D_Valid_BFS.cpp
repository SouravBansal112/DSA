/*
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>> n;
    vector<map<int,int>> adj(n+1);
    for(int i=1; i<n; i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=v;
        adj[v][u]=u;
    }
    vector<int> bfs(n+1);
    for(int i=0; i<n; i++){
        cin>>bfs[i];
    }
    vector<bool> visited(n+1,false);
    vector<int> level(n+1,-1);
    vector<int> parent(n+1,-1);
    int index=0;
    queue<int> q;
    q.push(bfs[index]);
    visited[bfs[index]]=true;
    index++;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        vector<int> children;
        for(auto i:adj[front]){
            if(!visited[i.first]){
                children.push_back(i.first);
            }
        }
        for (int i = 0; i < children.size(); i++) {
            if (index >= n || adj[front].count(bfs[index]) == 0 || visited[bfs[index]]) {
                cout << "No";
                return 0;
            }
            visited[bfs[index]] = true;
            q.push(bfs[index]);
            index++;
        }
    }
    cout<<"Yes";
    return 0;
}
    */

/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> bfs(n);
    for (int i = 0; i < n; i++) cin >> bfs[i];

    vector<bool> visited(n + 1, false);
    int index = 0;
    queue<int> q;
    q.push(bfs[index]);
    visited[bfs[index]] = true;
    index++;

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        // collect unvisited children
        vector<int> children;
        for (int nxt : adj[front]) {
            if (!visited[nxt]) children.push_back(nxt);
        }

        int k = children.size();
        // check that next k nodes in bfs[] are exactly these children
        unordered_set<int> childSet(children.begin(), children.end());
        for (int i = 0; i < k; i++) {
            if (index + i >= n || childSet.count(bfs[index + i]) == 0) {
                cout << "No";
                return 0;
            }
        }

        // mark visited and push to queue in BFS order
        for (int i = 0; i < k; i++) {
            visited[bfs[index]] = true;
            q.push(bfs[index]);
            index++;
        }
    }

    cout << "Yes";
    return 0;
}
*/





