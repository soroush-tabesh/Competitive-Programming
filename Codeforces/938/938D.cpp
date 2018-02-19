//In The Name of Allah
//Fri 27/11/96
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

int n,m;
ll w[M];
vector<pll> adj[M];
ll ans[M];

int main()
{
	Init;
	Solution();
	return 0;
}

void dijkstra(int r){
	vector<bool> mark(M);
	vector<int> par(M);
	vector<ll> dist(M,mod*10000);
	set<pair<pll,int> > cands; // (dist-vert)-par
	
	mark[r] = 1;
	par[r] = r;
	for(auto neib : adj[r]){
		cands.emplace(neib,r);
	}
	while(!cands.empty()){
		auto cur = *(cands.begin());
		cands.erase(cands.begin());
		if(mark[cur.F.S])
			continue;
		mark[cur.F.S] = 1;
		par[cur.F.S] = cur.S;
		dist[cur.F.S] = cur.F.F;
		for(auto neib : adj[cur.F.S]){
			if(mark[neib.S])
				continue;
			neib.F += cur.F.F;
			cands.emplace(neib,cur.F.S);
		}
	}
	int mx = r;
	forar(i,n){
		if(dist[i]+w[i] < dist[mx]+w[mx]){
			mx = i;
		}
	}
	ll cur = mx;
	ll clen = 0 ;
	while(cur != r){
		if(!ans[cur]){
			ans[cur] = w[mx] + clen*2;
		}
		clen += dist[cur] - dist[par[cur]];
		cur = par[cur];
	}
	ans[cur] = w[mx] + clen*2;
}

inline void Solution(){
	cin >> n >> m;
	forar(i,m){
		int a,b,c;
		cin >> a >> b >> c;
		--a;--b;
		adj[a].pb(mp(c,b));
		adj[b].pb(mp(c,a));
	}
	forar(i,n){
		cin >> w[i];
	}
	forar(i,n){
		if(!ans[i]){
			dijkstra(i);
		}
	}
	forar(i,n){
		cout << ans[i] << " ";
	}
}
