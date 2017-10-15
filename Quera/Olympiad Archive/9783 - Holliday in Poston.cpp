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
#define mp make_pair

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 1e5+5;

void Solution();

int n;
vector<int> adj[M];
vector<pii> edges;
int dp[20][M];
int h[M];
bool mark[M];
vector<pii> beenanc[M];
ll chdp[M];
ll ans;
int psum[20][M];

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

void dfsA(int v){
	mark[v] = 1;
	for(int neib : adj[v]){
		if(mark[neib])
			continue;
		h[neib] = h[v]+1;
		dp[0][neib] = v;
		dfsA(neib);
	}
}

void prep(){
	fori(j,1,20){
		forar(i,n){
			dp[j][i] = dp[j-1][dp[j-1][i]];
		}
	}
}

int query(int a,int b){
	if(h[a] < h[b])
		swap(a,b);
	for(int j = 19;j >= 0;j--){
		if(h[dp[j][a]] >= h[b])
			a = dp[j][a];
	}
	if(a == b)
		return a;
	for(int j = 19;j >= 0;j--){
		if(dp[j][a] != dp[j][b]){
			a = dp[j][a];
			b = dp[j][b];
		}
	}
	return dp[0][a];
}

void dfsB(int v){
	mark[v] = 0;
	for(int neib : adj[v]){
		if(!mark[neib])
			continue;
		dfsB(neib);
		chdp[v] += chdp[neib] + beenanc[neib].size();
	}
	ll d = beenanc[v].size();
	ans += d*(d-1)/2;
}

void prepsum(){
	forar(i,n){
		psum[0][i] = beenanc[dp[0][i]].size();
	}
	fori(j,1,20){
		forar(i,n){
			if((1<<j) > h[i])
				continue;
			psum[j][i] = psum[j-1][i] + psum[j-1][dp[j-1][i]];
		}
	}
}

ll getsum(int v,int len){
	if(len < 0)
		return 0;
	ll res = beenanc[v].size();
	for(int j = 19;j >= 0;j--){
		if((1<<j) <= len){
			len -= (1<<j);
			res += psum[j][v];
			v = dp[j][v];
		}
	}
	return res;
}

void Solution(){
	cin >> n;
	forar(i,n-1){
		int a,b;
		cin >> a >> b;
		adj[--b].pb(--a);
		adj[a].pb(b);
	}
	dfsA(0);
	prep();
	forar(i,n-1){
		int a,b;
		cin >> a >> b;
		int c = query(--a,--b);
		beenanc[c].pb(mp(a,b));
	}
	dfsB(0);
	prepsum();
	forar(i,n){
		for(pii p : beenanc[i]){
			ll a = getsum(p.F,h[p.F]-h[i]-1);
			ll b = getsum(p.S,h[p.S]-h[i]-1);
			ans += a+b;
		}
	}
	cout << ans << endl;
}
