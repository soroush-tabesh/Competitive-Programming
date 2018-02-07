//In The Name of Allah
//Tue 10/11/96
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
vector<pll> adj[M];
bool mark[M];
int par[M];
ll dist[M];
set<pair<pll,int> > cands; // (dist-vert)-par

int main()
{
	Init;
	Solution();
	return 0;
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
	mark[0] = 1;
	for(auto neib : adj[0]){
		cands.emplace(neib,0);
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
	if(!mark[n-1]){
		cout << -1 << endl;
		return;
	}
	vector<int> ans;
	int v = n-1;
	while(v){
		ans.pb(v);
		v = par[v];
	}
	ans.pb(0);
	reverse(ans.begin(),ans.end());
	for(int x : ans){
		cout << x+1 << " ";
	}
	cout << endl;
}
