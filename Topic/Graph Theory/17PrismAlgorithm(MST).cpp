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
#define  in(arr)        f(i,0,arr.size()) cin>>arr[i]
#define  out(arr)       f(i,0,arr.size()) cout<<arr[i]<<" "
#define  fast           ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

vi prism(ll v,vector<pl> adj[]){
    vi weight(v,INT_MAX);
    vector<bool> mst(v,false);
    vi parent(v);
    priority_queue<pi,vector<pi>,greater<pi>> pq;
    
    weight[0]=0;
    parent[0]=-1;
    pq.push({0,0});

    while(!pq.empty()){
        int p=pq.top().S;
        pq.pop();
        mst[p]=true;

        for(auto it:adj[p]){
            int child=it.F;
            int wght=it.S;
            if(mst[child]==false && wght<weight[child]){
                weight[child]=wght;
                pq.push({weight[child],child});
                parent[child]=p;
            }
        }
    }
    return parent;
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
        adj[v].pb({u,wt});
    }

    vi ans=prism(n,adj);
    f(i,1,ans.size()) cout<<ans[i]<<"->"<<i<<endl;

    return 0;
}