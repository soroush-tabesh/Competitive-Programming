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

int n;
vector<int> ch[M];
int stime[M];
int etime[M];
ll val[M];
ll seg[4*M];
bool lazy[4*M];
int tme;

int main()
{
	Init;
	Solution();
	return 0;
}

void dfs(int v){
	stime[v] = tme++;
	for(int neib : ch[v]){
		dfs(neib);
	}
	etime[v] = tme;
}

int init(int ind,int l,int r){
	if(l>=r)
		return 0;
	if(l==r-1)
		return seg[ind] = val[l];
	seg[ind] = 0;
	seg[ind] += init(ind*2+1,l,(l+r)/2);
	seg[ind] += init(ind*2+2,(l+r)/2,r);
	return seg[ind];
}

void toggle(int l,int r,int ind,int curl,int curr){
	if(l >= r)
		return;
	if(lazy[ind]){
		seg[ind] = curr-curl-seg[ind];
		lazy[ind] = 0;
		if(curl < curr-1){
			lazy[ind*2+1] = !lazy[ind*2+1];
			lazy[ind*2+2] = !lazy[ind*2+2];
		}
	}
	if(curr <= r && curl >= l){
		seg[ind] = curr-curl-seg[ind];
		if(curl < curr-1){
			lazy[ind*2+1] = !lazy[ind*2+1];
			lazy[ind*2+2] = !lazy[ind*2+2];
		}
	}else if(curr>l && curl < r){
		toggle(l,r,ind*2+1,curl,(curl+curr)/2);
		toggle(l,r,ind*2+2,(curl+curr)/2,curr);
		seg[ind] = seg[ind*2+1] + seg[ind*2+2];
	}
}

int query(int l,int r,int ind,int curl,int curr){
	if(l >= r)
		return 0;
	if(lazy[ind]){
		seg[ind] = curr-curl-seg[ind];
		lazy[ind] = 0;
		if(curl < curr-1){
			lazy[ind*2+1] = !lazy[ind*2+1];
			lazy[ind*2+2] = !lazy[ind*2+2];
		}
	}
	if(curr <= r && curl >= l){
		return seg[ind];
	}else if(curr>l && curl < r){
		int res = 0;
		res += query(l,r,ind*2+1,curl,(curl+curr)/2);
		res += query(l,r,ind*2+2,(curl+curr)/2,curr);
		return res;
	}else{
		return 0;
	}
}

void Solution(){
	cin >> n;
	forar(i,n-1){
		int a;
		cin >> a;
		ch[a-1].pb(i+1);
	}
	dfs(0);
	forar(i,n){
		cin >> val[stime[i]];
	}
	init(0,0,n);
	int q,v;
	cin >> q;
	string s;
	while(q--){
		cin >> s;
		cin >> v;
		v--;
		if(s == "get"){
			cout << query(stime[v],etime[v],0,0,n) << endl;
		}else{
			toggle(stime[v],etime[v],0,0,n);
		}
	}
}
