//In The Name of Allah
//Wed 19/7/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
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

const ll mod = 1e9+7,M = 2e5+5;

void Solution();

int n,k;
bool mark[M];
bool rmv[M];
vector<pii> edges;
vector<int> adj[M];
int dep[M];
int ch[M];
vector<int> cand;

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

int dfsA(int v){
	mark[v] = 1;
	int res = 1;
	for(int neib : adj[v]){
		if(mark[neib])
			continue;
		dep[neib] = dep[v]+1;
		res += dfsA(neib);
	}
	ch[v] = res;
	return res;
}

void dfsB(int v){
	mark[v] = 1;
	if(rmv[v]){
		cand.pb(ch[v]);
		return;
	}
	for(int neib : adj[v]){
		if(mark[neib])
			continue;
		dfsB(neib);
	}
}

void Solution(){
	cin >> n >> k;
	forar(i,n-1){
		int a,b,c;
		cin >> a >> b >> c;
		adj[--b].pb(--a);
		adj[a].pb(b);
		if(c)
			edges.pb({a,b});
	}
	dfsA(0);
	forar(i,edges.size()){
		if(dep[edges[i].F] < dep[edges[i].S]){
			rmv[edges[i].S] = 1;
		}else{
			rmv[edges[i].F] = 1;
		}
	}
	fill(mark,mark+n,0);
	dfsB(0);
	int ans = 0;
	sort(cand.begin(),cand.end());
	while(n > k && !cand.empty()){
		n-=cand.back();
		cand.pop_back();
		ans++;
	}
	if(n>k){
		cout << -1 << endl;
	}else{
		cout << ans << endl;
	}
}

