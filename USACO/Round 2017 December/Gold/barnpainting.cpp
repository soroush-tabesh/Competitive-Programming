//In The Name of Allah
//Sun 26/9/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("barnpainting.in","r",stdin),freopen("barnpainting.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define clamp(a,b,i) max(min(i,b),a)
#define infint 1000*1000*1000

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+100;

void Solution();

int n,k;
vector<int> adj[M];
ll dp[M][3];
int precolor[M];
bool mark[M];

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

void dfs(int v){
	if(mark[v])
		return;
	mark[v] = 1;
	if(precolor[v]){
		dp[v][precolor[v]-1] = 1;
	}else{
		dp[v][0] = dp[v][1] = dp[v][2] = 1;
	}
	for(int neib : adj[v]){
		if(mark[neib])
			continue;
		dfs(neib);
		dp[v][0] *= dp[neib][1] + dp[neib][2];
		dp[v][1] *= dp[neib][0] + dp[neib][2];
		dp[v][2] *= dp[neib][1] + dp[neib][0];
		dp[v][0] %= mod;
		dp[v][1] %= mod;
		dp[v][2] %= mod;
	}
}

void Solution(){
	cin >> n >> k;
	forar(i,n-1){
		int a,b;
		cin >> a >> b;
		adj[--a].pb(--b);
		adj[b].pb(a);
	}
	forar(i,k){
		int a,c;
		cin >> a >> c;
		precolor[--a] = c;
	}
	dfs(0);
	cout << ((dp[0][0] + dp[0][1] + dp[0][2])%mod) << endl;
}
