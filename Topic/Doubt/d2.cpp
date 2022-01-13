//5.	https://www.hackerearth.com/practice/algorithms/graphs/
depth-first-search/practice-problems/algorithm/longest-path-fecb5ecc/
// TLE in 3 test case

#include<iostream>
#include<iomanip>
#include<algorithm>
#include<math.h>
#include<climits>
#include<string>
#include<vector>
#include<array>
#include<deque>
#include<queue>
#include<stack>
#include<list>
#include<map>
#include<set>

using namespace std;

#define  endl            '\n'
#define  ll              long long
#define  vi              vector<int>
#define  vl              vector<ll>
#define  pb              push_back
#define  pi              pair<int,int>
#define  pl              pair<ll,ll>
#define  mp              make_pair
#define  F               first
#define  S               second
#define  f(i,in,n)       for(ll i=in;i<n;i++)
#define  fr(i,n,in)      for(ll i=n-1;i>=in;i--)
#define  in(arr)         f(i,0,arr.size()) cin>>arr[i]
#define  out(arr)        f(i,0,arr.size()) cout<<arr[i]<<" "
#define  srt(arr)        sort(arr.begin(),arr.end())
#define  fast            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int M=1000000007;

ll n,k,ans,step=0;
vi adj[100001],arr(100001),vis1(100001);

void bfs(int node){
    vi vis(n+1);
    vis[node]=1;
    vis1[node]=1;
    queue<pi> q;
    q.push({node,0});

    while(!q.empty()){
        ans=q.front().F;
        step=q.front().S;
        q.pop();
        for(auto it:adj[ans]){
            if(!vis[it]){
                q.push({it,step+1});
                vis[it]=1;
                vis1[it]=1;
            }
        }
    }
}


int main(){
    fast;

    ll u,v,no;
    cin>>n>>k;
    vi temp;
    f(i,1,n+1) {
        cin>>arr[i];
        if(arr[i]%k==0) temp.pb(i);
    }
    f(i,1,n){
        cin>>u>>v;
        if(arr[u]%k==0 && arr[v]%k==0){
            adj[u].pb(v);
            adj[v].pb(u);
        }
    }
    
    int res=0;
    f(i,0,temp.size()){
        if(!vis1[i]){
            bfs(temp[i]);
            bfs(ans);
            if(res<step) res=step;
            if(2*res>=temp.size()) break;
        }
    }
    cout<<res;
    return 0;
}