#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector <pair<int,int>> adj[n+1];

    //Take input
    for (int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    //Print Output
    for (int i=0;i<=n;i++){
        for (int j=0;j<adj[i].size();j++){
            cout<<i<<"-"<<adj[i][j].first<<","
                <<adj[i][j].second<<"\t";
        }
        cout<<endl;
    }

    return 0;
}