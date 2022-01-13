//Greedy Approach

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

vl shortestpath(ll v,vl adj[],ll src){
    vl dis(v,LLONG_MAX);
    dis[src]=0;
    queue<ll> q;
    q.push(src);

    while(!q.empty()){
        ll node=q.front();   
        q.pop();

        for (auto it:adj[node])
        if (dis[it]>dis[node]+1) {
            dis[it]=dis[node]+1;
            q.push(it);
        }
    }
    return dis;
}

int main(){
    fast;
    ll n,m;
    cin>>n>>m;
    vl adj[n];

    while(m--){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vl ans=shortestpath(n,adj,0);
    out(ans,ans.size())<<endl;

    return 0;
}