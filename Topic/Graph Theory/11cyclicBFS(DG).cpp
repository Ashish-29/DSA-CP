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
bool iscycle(ll V,vector<ll> adj[]){
    vl vis(V+1,0);
    queue <ll> q;
    
    f(i,1,V+1) for (auto it:adj[i]) vis[it]++;   //Find No of Indegree
    f(i,1,V+1) if  (!vis[i])        q.push(i);   //Find Indegree=0

    ll ct=0;
    while(!q.empty()){
        ll node=q.front(); q.pop();
        ct++;

        for (auto it:adj[node]) {
            vis[it]--;
            if(!vis[it]) q.push(it);
        }
    }
    if (ct==V) return false;
    else return true;
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

    if(iscycle(n,adj)) cout<<"Cycle Present";
    else cout<<"Cycle Not Present";

    return 0;
}