//All pair Shortest Path
//O(V^3)
//Work for both directed and undirected graph
//work for -ve edge wght but not for -ve cycle
//so,Used to detect -ve cycle

#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int V;

void printSolution(vector<vector<int>> dist){
    cout << "The following Matrix shows the shortest "
            "distances between every pair of vertices.\n\nX\t";
    
    for (int i = 0; i < V; i++) cout << i << "\t";
    cout << "\n\n";
    
    for (int i = 0; i < V; i++){
        cout << i << " ->\t";
        for (int j = 0; j < V; j++){
            if (dist[i][j] == INF) cout << "INF\t";
            else cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}

void floydWarshall(vector<vector<int>> dist){
    for (int k = 0; k < V; k++){
        for (int i = 0; i < V; i++){
            for (int j = 0; j < V; j++){
                if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INF && dist[i][k] != INF))
                    dist[i][j] =  dist[i][k] + dist[k][j];
            }
        }
    }
    printSolution(dist);
}

int main(){
    int E;
    cin >> V >> E;
    vector<vector<int>> graph(V, vector<int>(V, INF));

    for (int i = 0; i < V; i++) graph[i][i] = 0;

    while (E--){
        int u, v, wt;
        cin >> u >> v >> wt;
        graph[u][v] = wt;
    }

    floydWarshall(graph);

    return 0;
}