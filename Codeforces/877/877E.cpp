//In The Name of Allah
//Tue 25/7/96
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

int n,q,v,stime[M],etime[M],val[M],seg[4*M],lazy[4*M],tme;
vector<int> ch[M];

int main()
{
	Init;
	Solution();
	return 0;
}

void dfs(int v){
	stime[v] = tme++;
	for(int neib : ch[v])
		dfs(neib);
	etime[v] = tme;
}

int init(int ind=1,int l=0,int r=n){
	if(l>=r)
		return 0;
	if(l==r-1)
		return seg[ind] = val[l];
	int mid = (l+r)>>1;
	seg[ind] = init(ind<<1,l,mid) + init(ind<<1|1,mid,r);
	return seg[ind];
}

inline void pushiflazy(int ind,int curl,int curr){
	if(lazy[ind]){
		seg[ind] = curr-curl-seg[ind];
		lazy[ind] = 0;
		if(curl < curr-1){
			lazy[ind<<1] ^= 1;
			lazy[ind<<1|1] ^= 1;
		}
	}
}

void toggle(int l,int r,int ind=1,int curl=0,int curr=n){
	if(l >= r)
		return;
	pushiflazy(ind,curl,curr);
	if(curr <= r && curl >= l){
		seg[ind] = curr-curl-seg[ind];
		if(curl < curr-1){
			lazy[ind<<1] ^= 1;
			lazy[ind<<1|1] ^= 1;
		}
	}else if(curr>l && curl < r){
		int mid = (curl+curr)>>1;
		toggle(l,r,ind<<1,curl,mid);
		toggle(l,r,ind<<1|1,mid,curr);
		seg[ind] = seg[ind<<1] + seg[ind<<1|1];
	}
}

int query(int l,int r,int ind=1,int curl=0,int curr=n){
	if(l >= r)
		return 0;
	pushiflazy(ind,curl,curr);
	if(curr <= r && curl >= l){
		return seg[ind];
	}else if(curr>l && curl < r){
		int mid = (curl+curr)>>1,res=0;
		res += query(l,r,ind<<1,curl,mid);
		res += query(l,r,ind<<1|1,mid,curr);
		return res;
	}else{
		return 0;
	}
}

void Solution(){
	cin >> n;
	forar(i,n-1){
		cin >> v;
		ch[v-1].pb(i+1);
	}
	dfs(0);
	forar(i,n){
		cin >> val[stime[i]];
	}
	init();
	cin >> q;
	string s;
	while(q--){
		cin >> s;
		cin >> v;
		v--;
		if(s == "get"){
			cout << query(stime[v],etime[v]) << endl;
		}else{
			toggle(stime[v],etime[v]);
		}
	}
}
