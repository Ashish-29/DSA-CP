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

bool dfs(ll n,vl adj[],vl &vis,vl &curr_vis){
    vis[n]=1; curr_vis[n]=1;

    for (auto it:adj[n])
    if (!vis[it]){
        if(dfs(it,adj,vis,curr_vis)) return true;
    }
    else if (curr_vis[it]) return true;

    curr_vis[n]=0;
    return false;
}

bool iscycle(ll V,vl adj[]){
    vl vis(V+1,0),curr_vis(V+1,0);
    f(i,1,V+1) 
    if (!vis[i] && dfs(i,adj,vis,curr_vis)) return true;
    return false;
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
    }
  
    if (iscycle(n,adj)) cout<<"Cycle Present";
    else cout<<"Cycle Not Present";

    return 0;
}