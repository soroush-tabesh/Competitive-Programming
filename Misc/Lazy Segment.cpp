//In The Name of Allah
//Fri 6/11/96
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
int arr[M];
int lazy[M<<2]; // lazy set : childs not updated yet but current vertex has been updated

int main()
{
	Init;
	int _t;
	cin >> _t;
	while(--_t)
		Solution();
	return 0;
}

inline void push_lazy(int l,int r,int node){
	if(lazy[node]){ // lazy set in a non-leaf vertex
		if(l!=r){
			lazy[node<<1] = lazy[node<<1+1] = lazy[node];
		}else{
			arr[l] = lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int l,int r,int node,int ul,int ur,int uval){
	if(ur < l || ul > r || l > r)
		return;
	push_lazy(l,r,node);
	if(ul <= l && r <= ur){
		lazy[node] = uval;
		push_lazy(l,r,node);
		return;
	}
	update(l,(l+r)>>1,node>>1,ul,ur,uval);
	update((l+r)>>1+1,r,node>>1+1,ul,ur,uval);
}

int query(int l,int r,int node,int pos){
	push_lazy(l,r,node);
	if(l==r)
		return arr[l];
	if(pos <= (l+r)>>1)
		return query(l,(l+r)>>1,node>>1,pos);
	return query((l+r)>>1+1,r,node>>1+1,pos);
}

inline void Solution(){
	cin >> n;
	fill(seg,seg+M>>2,0);
	fill(lazy,lazy+M>>2,0);
	forar(i,n){
		int a,b;
		cin >> a >> b;
		update(1,M,0,a,b,i+1);
	}
	set<int> ans;
	fori(i,1,M){
		ans.insert(query(0,M,0,i));
	}
	cout << ans.size()-1 << endl;
}
