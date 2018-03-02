//In The Name of Allah
//Fri 12/12/96
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

const ll mod = 1e9+7,M = 1e5+100,infneg = -2e9;

void Solution();

int n,k;
ll w[M];
ll dp[M][110];
vector<int> adj[M];
ll ptr[M];

int main()
{
	Init;
	Solution();
	return 0;
}

struct cmp{
	bool operator()(int a,int b){
		return dp[a][ptr[a]+1]-dp[a][ptr[a]] > dp[b][ptr[b]+1]-dp[b][ptr[b]] ||
				(dp[a][ptr[a]+1]-dp[a][ptr[a]] == dp[b][ptr[b]+1]-dp[b][ptr[b]] && a<b);
	}
};

void dfs(int v,int pr){
	dp[v][0] = 0;
	set<int,cmp> cands;
	for(int neib : adj[v]){
		if(neib == pr)
			continue;
		dfs(neib,v);
		cands.insert(neib);
	}
	if(cands.empty()){
		fori(i,2,k+1)
			dp[v][i] = infneg;
		dp[v][1] = w[v];
		return;
	}
	fori(i,1,k+1){
		int c = *cands.begin();
		cands.erase(cands.begin());
		++ptr[c];
		cands.insert(c);
		if(dp[c][ptr[c]] == infneg)
			dp[v][i] = infneg;
		else
			dp[v][i] = dp[v][i-1] + dp[c][ptr[c]] - dp[c][ptr[c]-1];
	}
	dp[v][1] = max(dp[v][1],w[v]);
	cands.clear();
}

inline void Solution(){
	cin >> n >> k;
	forar(i,n){
		cin >> w[i];
	}
	forar(i,n-1){
		int a,b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(0,0);
	cout << dp[0][k] << endl;
}
