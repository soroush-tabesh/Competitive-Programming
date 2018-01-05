//In The Name of Allah
//Wed 13/10/96
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

const ll mod = 1e9+7,M = 1e5+100;

void Solution();

int n,q;
int dp[20][M];
const int mlg = 17;
int h[M];
int ch[M];
vector<int> adj[M];
bool mark[M];

int main()
{
	Init;
	Solution();
	return 0;
}

int dfs(int v,int dep=0){
	mark[v] = 1;
	h[v] = dep;
	for(int neib : adj[v]){
		if(!mark[neib]){
			dp[0][neib] = v;
			ch[v] += dfs(neib,dep+1);
		}
	}
	ch[v]++;
	return ch[v];
}

void prep(){
	dfs(0);
	fori(j,1,mlg+1)
		forar(i,n)
			dp[j][i] = dp[j-1][dp[j-1][i]];
}

pair<int,pii> query(int v,int u){
	bool is = false;
	if(h[v] < h[u])
		swap(u,v),is=true;
	for(int j = mlg;j >= 0;j--)
		if(h[dp[j][v]] >= h[u])
			v = dp[j][v];
	if(v == u)
		return mp(v,mp(-1,-1));
	for(int j = mlg;j >= 0;j--){
		if(dp[j][v] != dp[j][u]){
			v = dp[j][v];
			u = dp[j][u];
		}
	}
	if(is)
		swap(u,v);
	return mp(dp[0][v],mp(v,u));
}

void Solution(){
	cin >> n >> q;
	forar(i,n-1){
		int a,b;
		cin >> a >> b;
		adj[--a].pb(--b);
		adj[b].pb(a);
	}
	prep();
	forar(i,q){
		int a,b,c;
		cin >> a >> b >> c;
		a--;b--;c--;
		pair<int,pii> lca_ab = query(a,b),
		lca_ac = query(a,c),
		lca_bc = query(b,c);
		if(h[c] < h[lca_ab.F]){
			cout << 0 << endl;
			continue;
		}
		if(lca_ab.F == c){
			cout << n-ch[lca_ab.S.F]-ch[lca_ab.S.S] << endl;
		}else if(lca_ac.F == c || lca_bc.F == c){
			if(lca_ac.F != c)
				swap(a,b);
			int nt = (h[adj[c][0]] < h[c] ? adj[c][1] : adj[c][0]);
			pair<int,pii> tt = query(nt,a);
			if(tt.S.F == -1)
				cout << ch[c]-ch[nt] << endl;
			else
				cout << ch[c]-ch[tt.S.S] << endl;
		}else{
			cout << 0 << endl;
		}
	}
}
