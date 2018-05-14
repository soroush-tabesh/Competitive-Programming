//In The Name of Allah
//Wed 11/11/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+100;

void Solution();

int n,m;
vector<pair<int,pii> > lines;
pii dp[M];
struct segtree{
	int lazy[M*4];
	inline void init(){
		fill(lazy,lazy+(M*4),0);
	}
	inline void push_lazy(int node){
		if(lazy[node]){
			lazy[node*2] = lazy[node*2+1] = lazy[node];
			lazy[node] = 0;
		}
	}
	void update(int ul,int ur,int uval,int l = 1,int r = M,int node = 1){
		if(ur < l || ul > r || l > r)
			return;
		if(ul <= l && r <= ur){
			lazy[node] = uval;
			return;
		}
		push_lazy(node);
		update(ul,ur,uval,l,(l+r)/2,node*2);
		update(ul,ur,uval,(l+r)/2+1,r,node*2+1);
	}
	int query(int p,int l=1,int r=M,int node=1){
		if(l==r)
			return lazy[node];
		push_lazy(node);
		int mid = (l+r)/2;
		if(p <= mid)
			return query(p,l,mid,node*2);
		else
			return query(p,mid+1,r,node*2+1);
	}
} seg;

int main()
{
	Init;
	Solution();
	return 0;
}

inline void Solution(){
	cin >> n >> m;
	forar(i,n){
		int x1,x2,y;
		cin >> x1 >> x2 >> y;
		lines.pb(mp(y,mp(x1,x2)));
	}
	sort(lines.begin(),lines.end());
	forar(i,n){
		int left = seg.query(lines[i].S.F);
		int right = seg.query(lines[i].S.S);
		if(left == 0){
			dp[i].F = lines[i].S.F;
		}else if(lines[i].S.F <= (lines[left-1].S.F+lines[left-1].S.S)/2){
			dp[i].F = dp[left-1].F;
		}else{
			dp[i].F = dp[left-1].S;
		}
		if(right == 0){
			dp[i].S = lines[i].S.S;
		}else if(lines[i].S.S <= (lines[right-1].S.F+lines[right-1].S.S)/2){
			dp[i].S = dp[right-1].F;
		}else{
			dp[i].S = dp[right-1].S;
		}
		seg.update(lines[i].S.F,lines[i].S.S,i+1);
	}
	forar(i,m){
		int p;
		cin >> p;
		int res = seg.query(p);
		if(res == 0){
			cout << p << endl;
		}else if(p <= (lines[res-1].S.F+lines[res-1].S.S)/2){
			cout << dp[res-1].F << endl;
		}else{
			cout << dp[res-1].S << endl;
		}
	}
}
