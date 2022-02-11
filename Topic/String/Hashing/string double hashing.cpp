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
const int N=1e6+1;

//*****************************************************************************

// hash(s)= s[0] + s[1]*p + s[2]*p^2 +........+ s[n-1]*p^(n-1)  mod M

pl double_hash(string s){
    ll p1=31, p2=29;
    ll M1=1e9+7,M2=1e9+9;
    ll hash_value1=0, hash_value2=0;
    ll p_pow1=1, p_pow2=1;
 
    for(char c: s) {

        hash_value1=(hash_value1+(c-'a'+1)*p_pow1)%M1;
        hash_value2=(hash_value2+(c-'a'+1)*p_pow2)%M2;
       
        p_pow1=(p_pow1*p1)%M1;
        p_pow2=(p_pow2*p2)%M2;
    }
 
    return {hash_value1,hash_value2};
}

//*****************************************************************************
int main(){
    fast;

    string s;
    cin>>s;
    pl ans=double_hash(s);
    cout<<ans.F<<" "<<ans.S<<endl;

    return 0;
}