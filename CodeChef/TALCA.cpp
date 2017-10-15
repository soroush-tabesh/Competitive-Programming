//In The Name of Allah
//Sat 22/7/96
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

int n,q;
vector<int> adj[M];
int dp[20][M];
bool mark[M];
int h[M];

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

int query(int a,int b){
	if(h[a] < h[b])
		swap(a,b);
	for(int j = 19;j>=0;j--){
		if(h[dp[j][a]] >= h[b]){
			a = dp[j][a];
		}
	}
	if(a==b)
		return a;
	for(int j = 19;j>=0;j--){
		if(dp[j][a] != dp[j][b]){
			a = dp[j][a];
			b = dp[j][b];
		}
	}
	return dp[0][a];
}

void prep(){
	fori(j,1,20){
		forar(i,n){
			dp[j][i] = dp[j-1][dp[j-1][i]];
		}
	}
}

void dfs(int v){
	mark[v] = 1;
	for(int neib : adj[v]){
		if(mark[neib])
			continue;
		dp[0][neib] = v;
		h[neib] = h[v]+1;
		dfs(neib);
	}
}

void Solution(){
	cin >> n;
	forar(i,n-1){
		int a,b;
		cin >> a >> b;
		adj[--b].pb(--a);
		adj[a].pb(b);
	}
	dfs(0);
	prep();
	cin >> q;
	forar(i,q){
		int r,u,v;
		cin >> r >> u >> v;
		int rv = query(--r,--v);
		int ru = query(--u,r);
		int uv = query(u,v);
		int ansh = -1;
		int ans = -1;
		if(h[rv] > ansh){
			ansh = h[rv];
			ans = rv;
		}
		if(h[ru] > ansh){
			ansh = h[ru];
			ans = ru;
		}
		if(h[uv] > ansh){
			ansh = h[uv];
			ans = uv;
		}
		cout << ans+1 << endl;
	}
}
