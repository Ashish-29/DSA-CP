//https://cp-algorithms.com/data_structures/fenwick.html

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
int N=2e5+1;

//*****************************************************************************

/*
After the range update (l,r,x) the range sum query should return the following values:

sum[0,i] = 0                     // i < l
         = x*i − x*(l−1)         // l ≤ i ≤ r
         = x*r − x*(l-1)         // i > r
            
sum[0,i] = 0*i - (0)                     // i < l
         = x*i − (x*(l−1))               // l ≤ i ≤ r
         = 0*i - (x*(l-1)-x*r)           // i > r
        
We can write the range sum as difference of two terms, where we use B1 for first term and B2 for second term. 
The difference of the queries will give us prefix sum over [0,i].

    sum[0,i] = sum(B1,i) * i − sum(B2,i);

*/

vl tree1(N),tree2(N);

ll read(vl &tree, ll idx){    
    ll sum = 0;
    while (idx){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

ll prefix_sum(ll idx){
    return (read(tree1,idx) * idx - read(tree2,idx));
}

void update(vl &tree,ll idx, ll add){
    while (idx < N){
        tree[idx] += add;     
        idx += (idx & -idx);
    }
}

void range_add(ll l,ll r,ll add){

    update( tree1, l, add );
    update( tree1, r+1, -add );

    update( tree2, l, add*(l-1) );
    update( tree2, r+1,-add*r);

}

//*****************************************************************************

int main(){   
    fast;

    ll n,a;
    cin>>n;

    f(i,1,n+1){
        cin>>a;
        range_add(i,i,a);
    }

    ll q;
    cin>>q;
    while(q--){
        ll type;
        cin>>type;
        if(type==1){
            ll l,r;
            cin>>l>>r;
            ll ans=prefix_sum(r) - prefix_sum(l-1);
            cout<<ans<<endl;
        }
        else{
            ll l,r,add;
            cin>>l>>r>>add;
            range_add(l,r,add);
        }
    }

    return 0;
}