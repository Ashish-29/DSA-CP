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
void online(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

clock_t start_time,end_time;
void time(){
    #ifndef ONLINE_JUDGE
        double time_taken=double(end_time-start_time)/double(CLOCKS_PER_SEC);
        cout << fixed << setprecision(5);
        cout<<"Time taken is : "<<time_taken<<" sec "<<endl;
    #endif
}

//*****************************************************************************
const double PI=3.1415926535897932;
const int M=1e9+7;
const int N=1e6+1;

//*****************************************************************************








void JMD(){
    ll n,m,k;
    cin>>n;
    vl arr(n);
    in(arr);

    



    return ;
}

//*****************************************************************************
int main(){
    start_time = clock();
    fast;
    //online();

    int t=1;
    cin>>t;
    while(t--) JMD();

    end_time = clock();
    //time();
    return 0;
}