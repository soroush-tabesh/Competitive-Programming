//In The Name of Allah
//Tue 25/7/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(int i = 0; i < n;i++)
#define fori(i,a,b) for(int i = a; i < b;i++)
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

int n,q,v,tme,stime[M],etime[M],val[M],seg[4*M],lazy[4*M],rvst[M];
vector<int> ch[M];

int main()
{
	Init;
	Solution();
	return 0;
}

void dfs(int v = 0){
	stime[v] = tme++;
	rvst[stime[v]]=v;
	for(int neib : ch[v])
		dfs(neib);
	etime[v] = tme;
}

void init(int ind = 1,int l = 0,int r = n){
	if(l==r-1){
		seg[ind] = val[rvst[l]];
		return;
	}
	int mid = (l+r)>>1;
	init(ind<<1,l,mid);
	init(ind<<1|1,mid,r);
	seg[ind] = seg[ind<<1]+seg[ind<<1|1];
}

inline void pushiflazy(int ind,int curl,int curr){
	if(!lazy[ind])
		return;
	lazy[ind] = 0;
	int mid = (curl+curr)>>1;
	seg[ind<<1] = mid-curl-seg[ind<<1];
	seg[ind<<1|1] = curr-mid-seg[ind<<1|1];
	lazy[ind<<1] ^= 1;
	lazy[ind<<1|1] ^= 1;
}

void toggle(int l,int r,int ind = 1,int curl = 0,int curr = n){
	if(curr <= r && curl >= l){
		seg[ind] = curr-curl-seg[ind];
		lazy[ind] ^= 1;
		return;
	}
	if(curl >= r || curr <= l)
		return;
	pushiflazy(ind,curl,curr);
	int mid = (curl+curr)>>1;
	toggle(l,r,ind<<1,curl,mid);
	toggle(l,r,ind<<1|1,mid,curr);
	seg[ind] = seg[ind<<1] + seg[ind<<1|1];
}

int query(int l,int r,int ind=1,int curl=0,int curr=n){
	if(curr <= r && curl >= l)
		return seg[ind];
	if(curl >= r || curr <= l)
		return 0;
	pushiflazy(ind,curl,curr);
	int mid = (curl+curr)>>1;
	return query(l,r,ind<<1,curl,mid)+query(l,r,ind<<1|1,mid,curr);
}

inline void Solution(){
	cin >> n;
	for(int i = 1; i < n;i++){
		cin >> v;
		ch[v-1].pb(i);
	}
	for(int i = 0; i < n;i++){
		cin >> val[i];
	}
	dfs();
	init();
	cin >> q;
	string s;
	while(q--){
		cin >> s >> v;
		v--;
		if(s[0] == 'g'){
			cout << query(stime[v],etime[v]) << endl;
		}else{
			toggle(stime[v],etime[v]);
		}
	}
}
