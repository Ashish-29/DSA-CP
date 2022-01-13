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
vl tree(N);

//return sum of arr[1...idx];
ll read(ll idx){
    ll sum = 0;
    while (idx){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

//add=newvalue-oldvalue;
void update(ll idx, ll add){
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
    vl arr(n),temp(n);

    in(arr);
    temp=arr;
    srt(temp);

    f(i,0,n) arr[i]=lower_bound(all(temp),arr[i])-temp.begin()+1;

    ll inv=0;

    fr(i,0,n){
        inv+=read(arr[i]-1);
        update(arr[i],1);
    }
    
    cout<<inv<<endl;

    return 0;
}