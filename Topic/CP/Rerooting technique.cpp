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
#define  f(i,in,n)  for(int i=in;i<n;i++)
#define  fr(i,in,n) for(int i=n-1;i>=in;i--)
#define  in(x)      f(i,0,(int)x.size()) cin>>x[i]
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
const ll M=1e9+7;
const int N=2e5+1;

//*****************************************************************************
vi adj[N];
vl sum(N);
vl subt(N,1);
 
void dfs0(int u, int p) {
    for(int v : adj[u]) {
        if(v != p) {
            dfs0(v, u);
            subt[u] += subt[v];
 
            // Sum of distances from node 'u' = subt[v] + sum[v]
            // For each node 'w' belonging to the subtree of 'v', 
            //they would have to traverse one more edge to get to 'u'
 
            sum[u] += subt[v] + sum[v];
        }
    }
}
 
void dfs1(int u, int p) {
    for(int v : adj[u]) {
        if(v != p) {
            // Now, we are rooting the tree at 'v'
 
            // new_subt contains the number of nodes in the subtree of 'u' excluding the subtree of 'v'
            // In other words, new_subt contains the number of nodes in the subtree 'v' hanging from 'u'
            // Simply, it is equal to n - subt[v].
            
            ll new_subt = subt[u] - subt[v];           // cancel the contribution of 'v' made to the 'u'
            ll new_sum = sum[u] - (subt[v] + sum[v]);
 
            subt[v] += new_subt;
            sum[v] += new_subt + new_sum;
 
            dfs1(v, u);
        }
    }
}

//*****************************************************************************

int main(){
    fast;

    ll n,u,v;
    cin>>n;
    f(i,1,n){
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs0(1,-1);
    dfs1(1,-1);

    f(i,1,n+1) cout<<sum[i]<<" ";

    return 0;
}