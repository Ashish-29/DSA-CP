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
const int N=1e5+1;

//*****************************************************************************
//0-base: parent->P, L->2*P+1, R->2*P+2
//1-base: parent->P, L->2*P, R->2*P+1

vl arr(N),tree(4*N);

//1 base index of tree and array
void build_segment_tree (ll idx,ll st, ll en){
	if(st==en) {tree[idx]=arr[st];return;}
	ll mid=(st+en)/2;
	build_segment_tree(2*idx,st,mid);
	build_segment_tree(2*idx+1,mid+1,en);
	tree[idx]=tree[2*idx]+tree[2*idx+1];
}

ll query(ll idx,ll st,ll en,ll val){
	if(st==en) return st;
	
	ll L=tree[2*idx];
	ll R=tree[2*idx+1];
	ll mid=(st+en)/2;
	ll ans;

	if(val<=L) ans=query(2*idx,st,mid,val);
	else ans=query(2*idx+1,mid+1,en,val-L);
	return ans;
}

void update(ll idx,ll st,ll en,ll pos){
	if(st==en) {tree[idx]=arr[pos];return;}
	ll mid=(st+en)/2;
	if(pos<=mid) update(2*idx,st,mid,pos);
	else update(2*idx+1,mid+1,en,pos);
	tree[idx]=tree[2*idx]+tree[2*idx+1];
}

void JMD(){
	ll n,m;
	cin>>n>>m;
	f(i,0,n) cin>>arr[i];

	build_segment_tree(1,0,n-1);

	while(m--){
		ll type,pos;
		cin>>type>>pos;
		if(type==2) {
			ll ans=query(1,0,n-1,pos+1);
			cout<<ans<<endl;
		}
		else {
			arr[pos]=1-arr[pos];
			update(1,0,n-1,pos);
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
