#include<bits/stdc++.h>
using namespace std;

void __dbg() { cerr << endl; }
template<typename Arg,typename... Args>void __dbg(Arg A, Args... B){cerr<<" "<<A;__dbg(B...);}
#define dbg(...)  cerr << "{" << #__VA_ARGS__ << "}:", __dbg(__VA_ARGS__)

//*****************************************************************************
#define  endl       '\n'
#define  ll         long long
#define  pi         pair<int,int>
#define  pl         pair<ll,ll>
#define  F          first
#define  S          second
#define  vi         vector<int>
#define  vl         vector<ll>
#define  vvi        vector<vi>
#define  vvl        vector<vl>
#define  vpi        vector<pi>
#define  vpl        vector<pl>
#define  si         stack<int>
#define  qi         queue<int>
#define  pqd        priority_queue<int>
#define  pqa        priority_queue<int,vi,greater<int>>
#define  mi         map<int,int>
#define  pb         push_back
#define  mp         make_pair

//*****************************************************************************
#define  f(i,in,n)  for(ll i=in;i<n;i++)
#define  fr(i,in,n) for(ll i=n-1;i>=in;i--)
#define  in(x)      f(i,0,x.size()) cin>>x[i]
#define  out(x)     for(auto it:x) cout<<it<<" ";cout<<endl;
#define  clr(x)     memset(x, 0, sizeof(x))
#define  all(x)     begin(x),end(x)
#define  rev(x)     reverse(all(x))
#define  srt(x)     sort(all(x))
#define  srtd(x)    sort(all(x),greater<ll>())
#define  no         cout<<"NO"<<endl
#define  yes        cout<<"YES"<<endl
#define  fast       ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

//*****************************************************************************
const double PI=3.1415926535897932;
const int M=1e9+7;

//*****************************************************************************

const int N=1e6+1;
const int L = log2(N)+2; 
ll n,l,timer=0;

vi tin(N), tout(N), adj[N];
ll up[N][L]; 

void dfs(int node, int p=0){
    tin[node]=++timer;
    up[node][0] = p;
    f(i,1,l) up[node][i] = up[up[node][i-1]][i-1];
    for (int it : adj[node]) if (it != p) dfs(it,node);
    tout[node]=++timer;
}

//checking if p is an ancestor of c
bool isAncestor(int p, int c) {
    return (tin[p]<=tin[c] && tout[c]<=tout[p]);
}

int lca(int u, int v){
    if (isAncestor(u,v)) return u;
    if (isAncestor(v,u)) return v;
    
    fr(i,0,l) if (!isAncestor(up[u][i],v)) u=up[u][i];  
    return up[u][0];
}

int main(){
    fast;

    cin>>n;
    l=log2(n)+2;
    
    ll u,v;
    f(i,1,n){
        cin>>u>>v;
        adj[u].pb(v);   
        adj[v].pb(u);
    }

    dfs(1);
    tout[0]=++timer;

    ll q;
    cin>>q;
    while(q--){
        //find lesat commom ancestor (LCA) of u and v
        cin>>u>>v;
        ll ans=lca(u,v);
        cout<<ans<<endl;
    }

    return 0;
}