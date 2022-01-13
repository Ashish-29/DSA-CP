#include<bits/stdc++.h>
using namespace std;

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

ll max_dis,max_node;

void dfs(ll node,ll dis,vl adj[],vl &vis){
    vis[node]=1;
    if(dis>max_dis) {max_dis=dis;max_node=node;}

    for (auto it:adj[node]){
        if (!vis[it]) dfs(it,dis+1,adj,vis);        
    }
    return ;
}

ll dfsOfGameTheory(ll V,vl adj[]){
    vl vis(V+1);
    
    max_dis=0;
    dfs(1,0,adj,vis);

    f(i,0,V+1) vis[i]=0;
    max_dis=0;
    dfs(max_node,0,adj,vis);
    
    return max_dis;
}

int main(){
    fast;
    ll n,m;
    cin>>n>>m;
    vector <ll> adj[n+1];

    f(i,0,m) {
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    ll max_disis=dfsOfGameTheory(n,adj);
    cout<<max_disis<<endl;

    return 0;
}