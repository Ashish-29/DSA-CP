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

void dfs(ll n,vl adj[],vl &vis,stack<ll> &s){
    vis[n]=1;
    for (auto it:adj[n])
    if (!vis[it]) dfs(it,adj,vis,s);
    s.push(n);
}

stack<ll> dfsOfGameTheory(ll V,vl adj[]){
    vl vis(V+1,0);
    stack<ll> s;
    f(i,1,V+1) 
    if (!vis[i]) dfs(i,adj,vis,s);
    return s;
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
  
    stack<ll> ans=dfsOfGameTheory(n,adj);
    while(!ans.empty()) {cout<<ans.top()<<"\n";ans.pop();}

    return 0;
}