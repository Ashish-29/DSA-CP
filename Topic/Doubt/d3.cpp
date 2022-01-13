//4.	https://atcoder.jp/contests/abc182/tasks/abc182_e 

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

int main(){
    fast;

    ll h,w,n,m,a,b;
    cin>>h>>w>>n>>m;
    vector<vi> sq(h+1,vi(w+1,0));
    while(n--){
        cin>>a>>b;
        sq[a][b]=1;
    }
    while(m--){
        cin>>a>>b;
        sq[a][b]=2;
    }

    f(i,1,h+1){
        a=-1,b=-1;
        f(j,1,w+1){
            if(a==-1 && sq[i][j]!=2) a=j;
            if(sq[i][j]==2) a=-1;          
            if(sq[i][j]==1) {
                b=j;
                f(k,a,b) sq[i][k]=5;
                f(k,b+1,w+1) {
                    if(sq[i][k]==2) {j=k;break;}
                    else if(sq[i][k]==1) continue;
                    sq[i][k]=5;
                    if(k==w) j=w;
                }          
                a=-1;b=-1;
            }
        }
    }

    f(j,1,w+1){
        a=-1,b=-1;
        f(i,1,h+1){
            if(a==-1)if(sq[i][j]!=2) a=i; 
            if(sq[i][j]==2) a=-1;
            if(sq[i][j]==1) {
                b=i;
                f(k,a,b) sq[k][j]=5;
                f(k,b+1,w+1) {
                    if(sq[k][j]==2) {i=k;break;}
                    else if(sq[k][j]==1) continue;
                    sq[k][j]=5;
                    if(k==h) i=h;
                }        
                a=-1;b=-1;
            }
        }
    }

    int ct=0;
    f(i,1,h+1){
        f(j,1,w+1){
            // cout<<sq[i][j]<<" ";
            if(sq[i][j]==1 || sq[i][j]==5) ct++;   
        }
        // cout<<endl;
    }
    cout<<ct<<endl;
    return 0;
}