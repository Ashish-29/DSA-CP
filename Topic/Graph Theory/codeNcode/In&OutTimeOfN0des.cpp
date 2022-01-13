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

void dfs(ll n,vl adj[],vl &vis,vl &intime,vl &outime){
    vis[n]=1;
    static int time=1;
    intime[n]=time++;

    for (auto it:adj[n]){
        if (!vis[it]) dfs(it,adj,vis,intime,outime);        
    }

    outime[n]=time++;
    return ;
}

void dfsOfGameTheory(ll V,vl adj[]){
    vl vis(V+1),intime(V+1),outime(V+1);
    
    dfs(1,adj,vis,intime,outime);

    out(intime,V+1)<<"\t"; cout<<endl;
    out(outime,V+1)<<"\t"; cout<<endl;
    return;
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

    dfsOfGameTheory(n,adj);

    return 0;
}