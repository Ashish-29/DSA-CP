#include<bits/stdc++.h>
using namespace std;

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

//*****************************************************************************
#define  f(i,in,n)  for(ll i=in;i<n;i++)
#define  fr(i,in,n) for(ll i=n-1;i>=in;i--)
#define  deb(x)     cerr<< #x <<" = "<< x <<endl;
#define  deb2(x,y)  cerr<<#x<<"="<<x<<" & "<<#y<<"="<<y<<endl;
#define  in(x)      f(i,0,x.size()) cin>>x[i]
#define  out(x)     f(i,0,x.size()) cout<<x[i]<<" "<<"\n"[i+1!=x.size()]
#define  all(x)     begin(x),end(x)
#define  srt(x)     sort(all(x))
#define  no         cout<<"NO"<<endl
#define  yes        cout<<"YES"<<endl
#define  fast       ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

//*****************************************************************************
const double PI=3.1415926535897932;
const int M=1e9+7;
const int N=1e6+1;

//*****************************************************************************

vl tree(4*N);

ll query(ll idx,ll st,ll en,ll l, ll r){
    if(en<l || r<st) return 0;
    if(st>=l && en<=r) return tree[idx];
    ll mid=(st+en)/2;
    ll L=query(2*idx,st,mid,l,r);
    ll R=query(2*idx+1,mid+1,en,l,r);
    return L+R;
}

void update(ll idx,ll st,ll en,ll pos,ll val){
    if(st==en) {tree[idx]=val;return;}
    ll mid=(st+en)/2;
    if(pos<=mid) update(2*idx,st,mid,pos,val);
    else update(2*idx+1,mid+1,en,pos,val);
    tree[idx]=tree[2*idx]+tree[2*idx+1];
}

//*****************************************************************************
int main(){
    fast;

    ll n,a,ans;
    cin>>n;

    f(i,0,n){
        cin>>a;
        if(a==n) ans=0;
        else ans=query(1,1,n,a+1,n);
        update(1,1,n,a,1);
        cout<<ans<<" ";
    }
    
    return 0;
}