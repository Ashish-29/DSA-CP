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
const int M=1e9+7;
const int N=1e6+1;

//*****************************************************************************

// hash(s)= s[0] + s[1]*p + s[2]*p^2 +........+ s[n-1]*p^(n-1)  mod M

ll hashh[N];
ll p_pow[N];
 
ll power(ll a,ll n){
    if(n==0) return 1;
    if(n%2==0) return power((a*a)%M,n/2)%M;
    return (a*power((a*a)%M,n/2))%M;
}
 
ll compute_hash(string s){
    ll hash_value=0;
    p_pow[0]=1;
 
    f(i,0,s.size()){
        hash_value=(hash_value+(s[i]-'a'+1)*p_pow[i])%M;
        hashh[i]=hash_value;
        p_pow[i+1]=(p_pow[i]*p)%M;
    }
 
    return hash_value;
}
 
ll substring_hash(ll i,ll j){
    ll hash_value=0;
    
    if(i>0) hash_value=(hashh[j]-hashh[i-1]+M)%M;
    else    hash_value=hashh[j];
 
    ll mod_inv_p=power(p_pow[i],M-2);
    hash_value=(hash_value*mod_inv_p)%M;
 
    return hash_value;
}

//*****************************************************************************
int main(){
    fast;

    string s;
    cin>>s;
    ll ans=hash(s);
    cout<<ans<<endl;

    return 0;
}
