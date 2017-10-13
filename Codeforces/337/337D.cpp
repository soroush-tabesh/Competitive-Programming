//In The Name of Allah
//Mon 17/7/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cerr << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 1e5+5;

void Solution();

int n,m,d;
vector<int> adj[M];
bool haunted[M];
int par[M];
bool mark[M];
int maxchild[M];
int maxpar[M];
pii dpc[M];
int ans;

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

int dfsA(int v){
	mark[v] = 1;
	int res = -1;
	if(haunted[v])
		res = 0;
	for(int neib : adj[v]){
		if(mark[neib])
			continue;
		par[neib] = v;
		int r = dfsA(neib);
		if(r == -1)
			continue;
		if(r >= dpc[v].F){
			dpc[v].S = dpc[v].F;
			dpc[v].F = r;
		}else if(r > dpc[v].S){
			dpc[v].S = r;
		}
		res = max(res,r+1);
	}
	maxchild[v] = res;
	return res;
}

void dfsB(int v){
	mark[v] = 0;
	if(haunted[v])
		maxpar[v] = 0;
	if(v){
		if(maxpar[par[v]] != -1)
			maxpar[v] = max(maxpar[v],maxpar[par[v]]+1);
		if(dpc[par[v]].F != maxchild[v])
			maxpar[v] = max(maxpar[v],dpc[par[v]].F+2);
		else if(dpc[par[v]].S != -1)
			maxpar[v] = max(maxpar[v],dpc[par[v]].S+2);
	}
	if(max(maxpar[v],maxchild[v]) <= d)
		ans++;
	for(int neib : adj[v]){
		if(!mark[neib])
			continue;
		dfsB(neib);
	}
}

void Solution(){
	cin >> n >> m >> d;
	forar(i,m){
		int a;
		cin >> a;
		haunted[--a]=1;
	}
	forar(i,n-1){
		int a,b;
		cin >> a >> b;
		adj[--a].pb(--b);
		adj[b].pb(a);
	}
	forar(i,n)
		maxchild[i] = maxpar[i] = dpc[i].F = dpc[i].S = -1;
	dfsA(0);
	dfsB(0);
	cout << ans << endl;
}
