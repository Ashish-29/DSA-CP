//O(n+m)

#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> adj;

vector<bool> visited;
vector<int> tin, low;
vector<pair<int,int>> BRIDGE;
int timer;


void dfs(int node, int parent = -1) {
    visited[node] = true;
    tin[node] = low[node] = timer++;

    for (int child : adj[node]) {
        if (child == parent) continue;

        if (visited[child]) low[node] = min(low[node], tin[child]);
        else {
            dfs(child, node);
            low[node] = min(low[node], low[child]);
            if (low[child] > tin[node]) BRIDGE.emplace_back(node, child);
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) dfs(i);
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

    find_bridges();
    
    for(int i=0;i<BRIDGE.size();i++) 
       cout<<BRIDGE[i].first<<"--"<<BRIDGE[i].second<<endl;

    return 0;
}