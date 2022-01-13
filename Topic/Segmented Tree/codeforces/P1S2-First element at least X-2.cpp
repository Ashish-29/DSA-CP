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
//0-base: parent->P, L->2*P+1, R->2*P+2
//1-base: parent->P, L->2*P, R->2*P+1

vl arr(N),tree(4*N);

//1 base index of tree
void build_max_segment_tree  (ll idx,ll st, ll en){
    if(st==en) {tree[idx]=arr[st];return;}
    ll mid=(st+en)/2;
    build_max_segment_tree (2*idx,st,mid);
    build_max_segment_tree (2*idx+1,mid+1,en);
    tree[idx]=max(tree[2*idx],tree[2*idx+1]); 
}

ll query(ll idx,ll st,ll en,ll l, ll r){
    if(en<l || r<st) return LLONG_MIN;
    if(st>=l && en<=r) return tree[idx];
    ll mid=(st+en)/2;
    ll L=query(2*idx,st,mid,l,r);
    ll R=query(2*idx+1,mid+1,en,l,r);
    return max(L,R);
}

void update(ll idx,ll st,ll en,ll pos,ll val){
    if(st==en) {tree[idx]=val;return;}
    ll mid=(st+en)/2;
    if(pos<=mid) update(2*idx,st,mid,pos,val);
    else update(2*idx+1,mid+1,en,pos,val);
    tree[idx]=max(tree[2*idx],tree[2*idx+1]);
}

void JMD(){
    ll n,m;
    cin>>n>>m;
    f(i,0,n) cin>>arr[i];
    build_max_segment_tree(1,0,n-1);

    while(m--){
        int type;
        cin>>type;

        if(type==1){
            int i,v;
            cin>>i>>v;
            arr[i]=v;
            update(1,0,n-1,i,v);
        }
        else{
            ll x,l;
            cin>>x>>l;
            ll ans=n,lo=l,hi=n-1,mid,y;

            while(lo<=hi){
                mid=(lo+hi)/2;
                y=query(1,0,n-1,lo,mid);
                if(y>=x) {ans=mid;hi=mid-1;}
                else lo=mid+1;
            }
            if(ans==n) ans=-1;
            cout<<ans<<endl;
        }
    }

    return ;
}

//*****************************************************************************
int main(){
    fast;

    int t=1;
    // cin>>t;
    f(i,1,t+1){
        //cout<<"\nTest case "<<i<<":\n";
        JMD();
    }

    return 0;
}