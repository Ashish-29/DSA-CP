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
#define  f(i,in,n)  for(int i=in;i<n;i++)
#define  fr(i,in,n) for(int i=n-1;i>=in;i--)
#define  in(x)      f(i,0,(int)x.size()) cin>>x[i]
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
const double PI=3.1415926535897932;
const int M=1e9+7;
const int N=1e6+1;

//*****************************************************************************

class node {
  public:
    bool endOfWord;
    node *a[26];
 
    node(){
        this->endOfWord=false;
        f(i,0,26) this->a[i]=NULL;
    }
};
 
void insert(node *root,string s){
    f(i,0,s.size()){
        int c=s[i]-'a';
 
        if(root->a[c]==NULL)
        root->a[c]=new node();
 
        root=root->a[c];
    }
 
    root->endOfWord=true;
}
 
bool search(node *root,string s){
    f(i,0,s.size()){
        int c=s[i]-'a';
 
        if(root->a[c]==NULL)
        return false;
 
        root=root->a[c];
    }
 
    return root->endOfWord;
}

//*****************************************************************************
int main(){
    fast;

    node *root= new node();
 
    int q;
    cin>>q;
    while(q--){
        int type;
        string s;
        cin>>type>>s;
 
        if(type==0) insert(root,s);    
        else cout<<search(root,s)<<endl;    
    }

    return 0;
}