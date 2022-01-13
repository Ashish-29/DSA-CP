#include<bits\stdc++.h>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<array>
#include<deque>
#include<queue>
#include<stack>
#include<list>
#include<map>
#include<set>

using namespace std;

#define  endl            '\n'
#define  ll              long long
#define  vi              vector<int>
#define  vl              vector<ll>
#define  pb              push_back
#define  pi              pair<int,int>
#define  pl              pair<ll,ll>
#define  mp              make_pair
#define  F               first
#define  S               second
#define  f(i,in,n)       for(ll i=in;i<n;i++)
#define  fr(i,n,in)      for(ll i=n-1;i>=in;i--)
#define  in(arr)         f(i,0,arr.size()) cin>>arr[i]
#define  out(arr)        f(i,0,arr.size()) cout<<arr[i]<<" "
#define  srt(arr)        sort(arr.begin(),arr.end())
#define  fast            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define  M               1000000007

void JMD(){
    ll n,d;
    cin>>n>>d;

    vpi arr(n);
    f(i,0,n) cin>>arr[i].F>>arr[i].S;
    srt(arr);

    int i=0,j=1;
    ll sum=arr[0].S;

    while(i<j && j<n){
        sum+=arr[j].S;
        if(arr[j].F-arr[i].F>)
    }
    
}

int main(){
    fast;

    ll t;
    cin>>t;
    while(t--)
        
    JMD();
    return 0;
}