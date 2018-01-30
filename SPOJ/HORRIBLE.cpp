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

const ll mod = 1e9+7,M = 1e5+100;

void Solution();

int n,q;
struct segtree{
	ll seg[M<<2];
	ll lazy[M<<2]; // value being added to subtree
	inline void init(){
		fill(lazy,lazy+(M<<2),0);
		fill(seg,seg+(M<<2),0);
	}
	inline void push_lazy(int l,int r,int node){
		seg[node] += lazy[node]*(r-l+1);
		if(l!=r){
			lazy[node<<1] += lazy[node];
			lazy[node<<1|1] += lazy[node];
		}
		lazy[node] = 0;
	}
	void update(int ul,int ur,ll uval,int l = 1,int r = M,int node = 1){
		push_lazy(l,r,node);
		if(l > ur || r < ul)
			return;
		if(ul <= l && r<=ur){
			lazy[node] += uval;
			push_lazy(l,r,node);
			return;
		}
		int mid = (l+r)/2;
		update(ul,ur,uval,l,mid,node<<1);
		update(ul,ur,uval,++mid,r,node<<1|1);
		seg[node] = seg[node<<1] + seg[node<<1|1];
	}
	ll query(int ul,int ur,int l=1,int r=M,int node=1){
		if(l > ur || r < ul)
			return 0;
		push_lazy(l,r,node);
		if(ul <= l && r<=ur)
			return seg[node];
		ll res = 0;
		int mid = (l+r)/2;
		res += query(ul,ur,l,mid,node<<1);
		res += query(ul,ur,++mid,r,node<<1|1);
		return res;
	}
} sgt;

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
	cin >> n >> q;
	sgt.init();
	while(q--){
		int ty;
		cin >> ty;
		if(ty){
			int a,b;
			cin >> a >> b;
			cout << sgt.query(a,b) << endl;
		}else{
			int a,b,c;
			cin >> a >> b >> c;
			sgt.update(a,b,c);
		}
	}
}
