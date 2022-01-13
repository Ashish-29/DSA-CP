#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>using ordered_set = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;

//order_of_key(K) :Number of items strictly smaller than k;
//find_by_order(K) :k-th element in a set; return pointer;

//*****************************************************************************
#define  endl       '\n'
#define  ll         long long
#define  vl         vector<ll>
#define  f(i,in,n)  for(ll i=in;i<n;i++)
#define  in(x)      f(i,0,x.size()) cin>>x[i]
#define  out(x)     for(auto it:x) cout<<it<<" ";cout<<endl;
#define  fast       ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

//*****************************************************************************

//1- insert a number x into the set
//2- print the K'th element
//3- print the number of elements less than K

int main(){
    fast;

    ll q;
    cin>>q;
    ordered_set<ll> s;
   
    while(q--){
        ll type,k;
        cin>>type>>k;

        if(type==1) s.insert(k);      
        else if(type==2) cout<<*s.find_by_order(k)<<endl;     
        else cout<<s.order_of_key(k);
    }

    return 0;
}