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

vl arr(N);
vl tree(N);
ll n;

void update(ll idx, ll add){
    while (idx < N){
        tree[idx] += add;     
        idx += (idx & -idx);
    }
}

//return the lower index where cumulative sum >= val
//i.e sum[1....idx]>=val

ll lower_bound(ll val){
    ll idx=0,sum=0;

    fr(i,0,log2(n)+1){
        if(idx+(1<<i)>n) continue;

        ll curr=tree[idx+(1<<i)];
        if(sum+curr<val){
            sum+=curr;
            idx+=(1<<i);
        }
    }
    return idx+1;
}

//*****************************************************************************

int main(){
    fast;

    cin>>n;

    f(i,1,n+1){
        cin>>arr[i];
        update(i,arr[i]);
    }

    ll q;
    cin>>q;
    while(q--){
        ll type;
        cin>>type;
        if(type==1){
            ll val;
            cin>>val;
            ll ans=lower_bound(val);
            cout<<ans<<endl;
        }
        else{
            ll idx,val;
            cin>>idx>>val;
            ll add=val-arr[idx];
            arr[idx]=val;
            update(idx,add);  
        }
    }

    return 0;
}