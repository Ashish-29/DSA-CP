//Apply dsu (find MST)
#include <bits\stdc++.h>
using namespace std;

class Node{
  public:
    int u, v, wt;
    Node(int a, int b, int c){
        u = a;
        v = b;
        wt = c;
    }
};

bool comp(Node a, Node b){
    return a.wt < b.wt;
}

int find_par(int v, vector<int> &parent){
    if (v == parent[v]) return v;
    return parent[v] = find_par(parent[v], parent);
}

void union_set(int a, int b, vector<int> &parent, vector<int> &rank){
    a = find_par(a, parent);
    b = find_par(b, parent);
    if (a != b){
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<Node> edge;

    while (m--){
        int u, v, wt;
        cin >> u >> v >> wt;
        edge.push_back(Node(u, v, wt));
    }

    sort(edge.begin(), edge.end(), comp);
    vector<int> parent(n), rank(n, 0);

    for (int i = 0; i < n; i++) parent[i] = i;
    vector<Node> mst;

    for (auto it : edge){
        if (find_par(it.u, parent) != find_par(it.v, parent)){
            mst.push_back(it);
            if (mst.size() == n - 1) break;
            union_set(it.u, it.v, parent, rank);
        }
    }

    for (auto it : mst) cout << it.u << " - " << it.v << " (" << it.wt << ")" << endl;
    
    return 0;
}
