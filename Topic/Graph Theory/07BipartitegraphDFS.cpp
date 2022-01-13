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

bool dfs(ll n,vl adj[],vl &col){
    for (auto it:adj[n]){
        if (col[it]==-1){
            col[it]=1-col[n];
            if (!dfs(it,adj,col)) return false;    
        }
        else if (col[it]==col[n]) return false;
    }
    return true;
}

bool dfsOfGameTheory(ll V,vl adj[]){
    vl col(V+1,-1);
    f(i,1,V+1){
        if (col[i]==-1){
            col[i]=0;
            if(!dfs(i,adj,col)) return false;
        }
    }
    return true;
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

    if(dfsOfGameTheory(n,adj)) cout<<"Bipartite Graph";   
    else cout<<"Not Bipartite Graph";

    return 0;
}