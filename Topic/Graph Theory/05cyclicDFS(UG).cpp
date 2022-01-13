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

bool iscycle(ll n,ll prv,vl adj[],vl &vis){
    vis[n]=1;

    for (auto it:adj[n]){
        if (!vis[it] && iscycle(it,n,adj,vis)) return true ;
        else if (it!=prv) return true;
    }
    return false;
} 

bool dfsOfGameTheory(ll V,vl adj[]){
    vl vis(V+1,0);
    f(i,1,V+1){
        if (!vis[i] && iscycle(i,-1,adj,vis)) return true;
    }
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
        adj[v].pb(u);
    }
  
    if (dfsOfGameTheory(n,adj)) cout<<"Cycle Present";
    else cout<<"Cycle Not Present";

    return 0;
}