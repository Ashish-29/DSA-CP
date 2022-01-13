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

vector<ll> bfsOfGameTheory(ll V,vector<ll> adj[]){
    vector<ll> bfs,vis(V+1,0);

    f(i,1,V+1) {
        if (!vis[i]){
            queue<ll> q;
            q.push(i); vis[i]=1;

            while(!q.empty()){
                ll node=q.front();
                bfs.push_back(node);
                q.pop();

                for (auto it: adj[node]) {
                    if (!vis[it]){
                        q.push(it);
                        vis[it]=1;
                    }
                }
            }
        }
    }

    return bfs;
}

int main(){
    ll n,m;
    cin>>n>>m;
    vector <ll> adj[n+1];

    f(i,0,m) {
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll> ans=bfsOfGameTheory(n,adj);
    
    f(i,0,n) cout<<ans[i]<<endl;

    return 0;
}