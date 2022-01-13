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

void dfs(ll n,vl adj[],vl &stdfs,vl &vis){
    vis[n]=1;
    stdfs.pb(n);

    for (auto it:adj[n]){
        if (!vis[it]){
            dfs(it,adj,stdfs,vis);
        }
    }
}

vl dfsOfGameTheory(ll V,vl adj[]){
    vl storedfs,vis(V+1,0);
    f(i,1,V+1){
        if (!vis[i]){
            dfs(i,adj,storedfs,vis);
        }
    }
    return storedfs;
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

    vl ans=dfsOfGameTheory(n,adj);   
    out(ans,ans.size())<<endl;

    return 0;
}