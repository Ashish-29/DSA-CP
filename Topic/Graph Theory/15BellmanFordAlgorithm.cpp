//Single Source Shortest Path
//DP Approach ->   O(EV)
//Work for directed graph only (change undirected --> directed)
//work for -ve edge wght but not for -ve cycle
//so,Used to detect -ve cycle

#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

struct node{
    int u;
    int v;
    int wt;
    node(int first, int second, int weight){
        u = first;
        v = second;
        wt = weight;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<node> edges;
    vector<int> dist(n, inf);
    
    while (m--){
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u, v, wt));
    }

    int src;
    cin >> src;
    dist[src] = 0;

    for (int i = 1; i < n ; i++){                       //(n-1) times
        for (auto it : edges){                          // m times
            if (dist[it.u] + it.wt < dist[it.v]){
                dist[it.v] = dist[it.u] + it.wt;
            }
        }
    }

    int fl = 0;
    for (auto it : edges){
        if (dist[it.u] + it.wt < dist[it.v]){
            cout << "negative Cycle";
            fl = 1;
            break;
        }
    }

    if (!fl){
        for (int i = 1; i <= n; i++){
            cout << src << " -> " << i << " = " << dist[i] << endl;
        }
    }

    return 0;
}
