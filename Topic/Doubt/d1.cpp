//https://codeforces.com/problemset/problem/1569/C

#include<bits/stdc++.h>
using namespace std;

#define  endl            '\n'
#define  ll              long long
#define  pi              pair<int,int>
#define  pl              pair<ll,ll>
#define  F               first
#define  S               second
#define  vi              vector<int>
#define  vl              vector<ll>
#define  vvi             vector<vi>
#define  vpi             vector<pi>
#define  si              stack<int>
#define  qi              queue<int>
#define  pqd             priority_queue<int>
#define  pqa             priority_queue<int,vi,greater<int>>
#define  mi              map<int,int>
#define  pb              push_back
#define  i(a)            int a;cin>>a
#define  l(a)            long long a;cin>>a
#define  s(a)            string a;cin>>a
#define  f(i,in,n)       for(ll i=in;i<n;i++)
#define  fr(i,n,in)      for(ll i=n-1;i>=in;i--)
#define  in(arr)         f(i,0,arr.size()) cin>>arr[i]
#define  out(arr)        f(i,0,arr.size()) cout<<arr[i]<<" "
#define  srt(arr)        sort(arr.begin(),arr.end())
#define  fast            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int M=998244353;
const int N=200000;
vi fac(N+1);
ll inv=1;

void INV(){
    ll a=2,m=M-2;
    while(m){
        if(m%2){
            inv=(inv*a)%M;
            m--;
        }
        else{
            a=(a*a)%M;
            m/=2;
        }
    }
}

void factorial(){
    fac[0]=fac[1]=1;
    f(i,2,N+1) fac[i]=(fac[i-1]*1ll*i)%M;
}

void JMD(){
    l(n);
    vi arr(n);
    mi mp;
    int a=0,b=0;

    f(i,0,n){
        cin>>arr[i];
        mp[arr[i]]++;
        if(arr[i]>=a){
            b=a;
            a=arr[i];
        }
        else if(arr[i]>b){
            b=arr[i];
        }
    }
    
    if(a-b>1) cout<<0;
    else if(a==b) cout<<fac[n];
    else cout<<fac[n] *inv %M;
    cout<<endl;

    return;
}
 
int main(){
    fast;
    factorial();
    INV();
 
    i(t);
    while(t--)
        
    JMD();
    return 0;
}