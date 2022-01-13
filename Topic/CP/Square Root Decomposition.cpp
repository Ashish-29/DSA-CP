//query from [l,r] in O(sqrt(n));
// like sum,max,min,......

#include<bits/stdc++.h>
using namespace std;

//*****************************************************************************
#define  endl       '\n'
#define  ll         long long
#define  vl         vector<ll>
#define  f(i,in,n)  for(ll i=in;i<n;i++)
#define  in(x)      f(i,0,x.size()) cin>>x[i]
#define  out(x)     for(auto it:x) cout<<it<<" ";cout<<endl;
#define  fast       ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

//*****************************************************************************

int main(){
    fast;

    ll n,t,l,r;
    cin>>n>>t;
    vl arr(n);
    in(arr);

    ll len=(int)sqrtl(n)+1;
    vl b(len);

    f(i,0,n) b[i/len]+=arr[i];

    while(t--){
        cin>>l>>r;
        l--;r--;
        ll sum=0;

        while(l<=r){
            if(l%len==0 && l+len-1<=r) {sum+=b[l/len];l+=len;}
            else {sum+=arr[l];l++;}
        }

        cout<<sum<<endl;
    }

    return 0;
}

//Mo's Algorith based on this.
//(input all query and sort in some manner and then answer one by one)