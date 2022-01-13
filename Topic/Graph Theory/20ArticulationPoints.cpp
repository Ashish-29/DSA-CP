//O(n+m)

#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> adj;

vector<bool> visited,IS_CUTPOINT;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children=0;

    for (int to : adj[v]) {
        if (to == p) continue;

        if (visited[to]) low[v] = min(low[v], tin[to]);
        else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1) IS_CUTPOINT[v]=1;
            ++children;
        }
    }

    if(p == -1 && children > 1) IS_CUTPOINT[v]=1;
}

void find_cutpoints() {
    timer = 0;
    visited.assign(n,0);
    IS_CUTPOINT.assign(n,0);
    tin.assign(n, -1);
    low.assign(n, -1);

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) dfs (i);
    }
}

int main(){
    cin>>n>>m;
    adj.resize(n);

    while(m--){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    find_cutpoints();
    
    for(int i=0;i<n;i++) 
    if(IS_CUTPOINT[i]) cout<<i<<endl;

    return 0;
}