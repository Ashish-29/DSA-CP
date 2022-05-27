#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj, adj_rev;
vector<bool> used;
vector<int> order, component;

void dfs1(int v) {
    used[v] = true;
    for (auto u : adj[v]) if (!used[u]) dfs1(u);
    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);
    for (auto u : adj_rev[v]) if (!used[u]) dfs2(u);
}

int main() {
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    adj_rev.resize(n+1);

    while(m--) {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }

    used.assign(n+1, false);
    for (int i = 1; i <= n; i++) if (!used[i]) dfs1(i);
    reverse(order.begin(), order.end());

    used.assign(n+1, false);
    for (auto v : order)
    if (!used[v]) {
        dfs2 (v);
        for (auto it:component) cout<<it<<" ";cout<<endl;
        component.clear();
    }

    return 0;
}