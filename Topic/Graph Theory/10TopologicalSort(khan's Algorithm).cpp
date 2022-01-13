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

//Kahn's Algorithm
vl bfsOfGameTheory(ll V,vector<ll> adj[]){
    vl in_degree(V+1,0),toposort;
    queue <ll> q;
    
    f(i,1,V+1) for (auto it:adj[i]) in_degree[it]++;   //Find No of Indegree
    f(i,1,V+1) if  (!in_degree[i])  q.push(i);         //Find Indegree=0  (start position)

    while(!q.empty()){ 
        ll node=q.front(); q.pop();
        toposort.pb(node); 

        for (auto it:adj[node]) {
            in_degree[it]--;
            if(!in_degree[it]) q.push(it);
        }
    }
    return toposort;
}

int main(){
    ll n,m;
    cin>>n>>m;
    vector <ll> adj[n+1];

    f(i,0,m) {
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    vl ans=bfsOfGameTheory(n,adj);  
    out(ans,ans.size())<<endl;

    return 0;
}