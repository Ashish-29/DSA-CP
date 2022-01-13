//Single Source Shortest Path
//Greedy Approach ->   O(E*log(V))
//Work for both directed and undirected graph
//NOT work for -ve edge wght or -ve cycle

#include<bits\stdc++.h>
using namespace std;

#define  endl           '\n'
#define  ll             long long
#define  vi             vector<int>
#define  vl             vector<ll>
#define  pb             push_back
#define  pi             pair<int,int>
#define  pl             pair<ll,ll>
#define  mp             make_pair
#define  F              first
#define  S              second
#define  f(i,in,n)      for(ll i=in;i<n;i++)
#define  in(arr,n)      f(i,0,n) cin>>arr[i]
#define  out(arr,n)     f(i,0,n) cout<<arr[i]
#define  fast           ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

vl shortestpath(ll v,vector<pl> adj[],ll src){
    vl dis(v+1,LLONG_MAX);
    dis[src]=0;
    priority_queue<pl,vector<pl>,greater<pl>> pq; //ascending order
    pq.push({0,src});

    while(!pq.empty()){
        ll dist=pq.top().F;
        ll node=pq.top().S;   
        pq.pop();

        for (auto it:adj[node])
        if (dis[it.F]>dist+it.S) {
            dis[it.F]=dist+it.S;
            pq.push({dis[it.F],it.F});
        }
    }
    return dis;
}

int main(){
    fast;
    ll n,m;
    cin>>n>>m;
    vector<pl> adj[n+1];

    while(m--){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].pb({v,wt});
        // adj[v].pb({u,wt});
    }

    vl ans=shortestpath(n,adj,1);
    f(i,1,ans.size()) cout<<1<<"->"<<i<<" ="<<ans[i]<<endl;

    return 0;
}