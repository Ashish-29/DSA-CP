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
#define  f(i,in,n)       for(ll i=in;i<n;i++)
#define  fr(i,in,n)      for(ll i=n-1;i>=in;i--)
#define  in(arr)         f(i,0,arr.size()) cin>>arr[i]
#define  out(arr)        f(i,0,arr.size()) cout<<arr[i]<<" "
#define  srt(arr)        sort(arr.begin(),arr.end())
#define  fast            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

const int M=1000000007;

struct node{
	int zero=M;
	int two;
	int five;
	pi parent;
};

void JMD(){
	ll n,a,ct;
	cin>>n;
	vector<vector<node>> v(n,vector<node>(n));

    f(i,0,n){
		f(j,0,n){
			cin>>a;
		    
			ct=0;
			while(a>1 && a%2==0){
				a/=2;
				ct++;
			}
			v[i][j].two=ct;

            ct=0;
			while(a>1 && a%5==0){
				a/=5;
				ct++;
			}
			v[i][j].five=ct;
		}
	}

    set<pair<int,pair<pi,pi>>> st;
	v[0][0].zero=min(v[0][0].two,v[0][0].five);
	v[0][0].parent={-1,-1};
	st.insert({v[0][0].zero,{{0,0},{}}});

	while(!st.empty()){
		auto p=*st.begin();
		st.erase(p);

		int x=p.S.F,y=p.S.S,z=p.F;
cout<<x<<" "<<y<<" "<<z<<endl;
		int nx=p.S.F+1,ny=p.S.S+1,nz;

        if(y==n-1 && x==n-1) {break;}

		if(nx<n){
            nz=z+min(v[nx][y].two,v[nx][y].five);
			if(v[nx][y].zero>nz){
				st.erase({v[nx][y].zero,{nx,y}});
				v[nx][y].zero=nz;
				v[nx][y].parent={x,y};
				st.insert({v[nx][y].zero,{nx,y}});
			}
		}
		if(ny<n){
            nz=z+min(v[x][ny].two,v[x][ny].five);
			if(v[x][ny].zero>nz){
				st.erase({v[x][ny].zero,{x,ny}});
				v[x][ny].zero=nz;
				v[x][ny].parent={x,y};
				st.insert({v[x][ny].zero,{x,ny}});
			}
		}
	}

	cout<<v[n-1][n-1].zero<<endl;

	stack<char> s;
	pi idx={n-1,n-1};

	while(idx.F!=0 || idx.S!=0){
        pi pidx=v[idx.F][idx.S].parent;

		if(pidx.F==idx.F) s.push('R');
		else s.push('D');

		idx=pidx;
	}

	while(!s.empty()){
		cout<<s.top();
		s.pop();
	}

	return ;
}

int main(){
	fast;

	// int t;
	// cin>>t;
	// while(t--)

	JMD();
	return 0;
}