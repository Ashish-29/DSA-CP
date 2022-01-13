//https://www.topcoder.com/thrive/articles/Binary%20Indexed%20Trees#lastbit

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
/*

binary     001    010      011      100      101     110     111    1000
tree idx-   1      2        3        4        5       6       7       8
store sum  1-1    1-2      3-3      1-4      5-5     5-6     7-7     1-8

tree[i] store sum of arr[L.....i] where,
L=i-(i & -i)+1    //keep LSB of i off and increase by 1

Now,if we have to calculate sum[1...7],then
    7 = 4 + 2 + 1    ( 111 = 100 + 010 + 001 )

    sum[1..7] = sum[7...7] + sum[5...6] + sum[1...4]           
    sum[1..7] =   tree[7]  +   tree[6]  +  tree[4]             (7-->6-->4-->0)


*/

vl arr(N),tree(N);

//LSB of x = (x & -x)

//return sum of arr[1...idx];
ll read(ll idx){     //O(log2n)
    ll sum = 0;
    while (idx){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

//add=newvalue-oldvalue;
void update(ll idx, ll add){  //O(log2n)
    while (idx < N){
        tree[idx] += add;     
        idx += (idx & -idx);
    }
}

//*****************************************************************************

int main(){   
    fast;

    ll n;
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
            ll idx;
            cin>>idx;
            ll ans=read(idx);   
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