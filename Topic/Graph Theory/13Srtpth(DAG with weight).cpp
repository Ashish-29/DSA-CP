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

void toposort(ll n,vector<pl> adj[],vl &vis,stack<ll> &s){
    vis[n]=1;
    for (auto it:adj[n]) if (!vis[it.F]) toposort(it.F,adj,vis,s);
    s.push(n);
}

vl shortestpath(ll V,vector<pl> adj[],ll src){  
    vl vis(V,0);
    stack<ll> s;
    toposort(src,adj,vis,s);

    vl dis(V,LLONG_MAX);
    dis[src]=0;
    
    while (!s.empty()){
        ll node=s.top();
        s.pop();
    
        if(dis[node]!=LLONG_MAX){
            for(auto it:adj[node]){
                if(dis[it.F]>dis[node]+it.S){
                    dis[it.F]=dis[node]+it.S;
                }
            }
        }
    }
    return dis;
}

int main(){
    fast;
    ll n,m;
    cin>>n>>m;
    vector<pl> adj[n];

    while(m--){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].pb({v,wt});
    }

    vl ans=shortestpath(n,adj,0);
    out(ans,ans.size())<<endl;
    
    return 0;
}