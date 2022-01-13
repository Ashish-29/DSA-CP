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
//maximum number of bits in binary representation of N = log2(N);
const int L = log2(N)+2; 

ll up[N][L];
vl adj[N];
ll n,l;

//up[i][j]->store (2^j)th ancestors of i.
//up[i][j] = up [up[i][j-1]] [j-1] ;

/*
let node=x;
if
2^0 th (1) ancestor of x : up[x][0]=a;
2^1 th (2) ancestor of x : up[x][1]=b;
2^2 th (4) ancestor of x : up[x][2]=c;
2^3 th (8) ancestor of x : up[x][3]=d;

then, 
2^4 th (16) ancestors of x= 2^3 th (8) ancestors of d 
i.e up[x][4]=up[up[x][3]][3];

*/

void dfs(int node, int p=0){
    up[node][0] = p;
    f(i,1,l) up[node][i] = up[up[node][i-1]][i-1];
    for (int it : adj[node]) if (it != p) dfs(it,node);
}

 //return the y-th ancestor of x
int lift(int x, int y){
    f(i,0,l){
        if ((1<<i)&y){
            x=up[x][i];
            y-=(1<<i);
        }
    }
    return x;
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

    ll q;
    cin>>q;
    while(q--){
        //find vth ancestor of u
        cin>>u>>v;
        ll ans=lift(u,v);
        cout<<ans<<endl;
    }

    return 0;
}