#include<bits/stdc++.h>
using namespace std;

#define  ll             long long
#define  pb             push_back
#define  mp             make_pair
#define  vi             vector<int>
#define  vl             vector<ll>
#define  pi             pair<int,int>
#define  pl             pair<ll,ll>
#define  F              first
#define  S              second
#define  f(i,in,n)      for(ll i=in;i<n;i++)
#define  read(arr,n)    f(i,0,n) cin>>arr[i]
#define  fast           ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

bool bfsOfGameTheory(ll V,vector<ll> adj[]){
    vector<ll> vis(V+1,0);

    f(i,1,V+1) {
        if (!vis[i]){
            queue<pl> q;
            q.push({i,-1}); vis[i]=1;

            while(!q.empty()){
                ll node=q.front().F;
                ll prvnode=q.front().S;
                q.pop();

                for (auto it:adj[node]) {
                    if(it!=prvnode){
                        if (vis[it]==1) return true;
                        q.push({it,node});
                        vis[it]=1;
                    }
                }
            }
        }
    }

    return false;
}

int main(){
    ll n,m;
    cin>>n>>m;
    vector <ll> adj[n+1];

    f(i,0,m) {
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    bool ans=bfsOfGameTheory(n,adj); 
    if (ans) cout<<"Cycle Present";
    else cout<<"Cycle Not Present";
    
    return 0;
}