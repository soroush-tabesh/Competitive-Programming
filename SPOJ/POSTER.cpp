//In The Name of Allah
//Sat 7/11/96
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

const ll mod = 1e9+7,M = 1e7+100;

void Solution();

int n;
struct segtree{
	set<int> ans;
	int lazy[M*4];
	inline void init(){
		ans.clear();
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
	void query(int l=1,int r=M,int node=1){
		if(lazy[node]){
			ans.insert(lazy[node]);
			return;
		}
		if(l==r)
			return;
		query(l,(l+r)/2,node*2);
		query((l+r)/2+1,r,node*2+1);
	}
} seg;

int main()
{
	Init;
	int _t;
	cin >> _t;
	while(_t--)
		Solution();
	return 0;
}

inline void Solution(){
	cin >> n;
	seg.init();
	forar(i,n){
		int a,b;
		cin >> a >> b;
		seg.update(a,b,i+1);
	}
	seg.query();
	cout << seg.ans.size() << endl;
}
