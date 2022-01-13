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

bool bfsOfGameTheory(ll V,vector<ll> adj[]){
    vi col(V+1,-1);

    f(i,1,V+1) {
        if (col[i]==-1){
            queue<ll> q;
            q.push(i); col[i]=0;

            while(!q.empty()){
                ll node=q.front();
                q.pop();

                for (auto it:adj[node]) {
                    if (col[it]==-1){
                        q.push(it); 
                        col[it]=1-col[node];   
                    }
                    else if (col[it]==col[node]) return false;   
                }
            }
        }
    }
    return true;
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

    if (bfsOfGameTheory(n,adj)) cout<<"Bipartite Graph";
    else cout<<"Not bipartite graph";
    
    return 0;
}