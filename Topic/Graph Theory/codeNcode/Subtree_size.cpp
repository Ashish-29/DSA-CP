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

ll dfs(ll n,vl adj[],vl &vis,vl &size){
    vis[n]=1;

    for (auto it:adj[n]){
        if (!vis[it]) size[n]+=dfs(it,adj,vis,size);        
    }

    return size[n];
}

vl dfsOfGameTheory(ll V,vl adj[]){
    vl vis(V+1);
    vl size(V+1,1);
    
    size[1]=dfs(1,adj,vis,size);
    
    return size;
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

    vl sz=dfsOfGameTheory(n,adj);
    f(i,1,n+1) cout<<sz[i]<<" ";
    cout<<endl;

    return 0;
}