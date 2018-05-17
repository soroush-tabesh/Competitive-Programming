//In The Name of Allah
//Thu 27/2/97
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

int n,ans;
vector<int> adj[M];
bool mark[M];

int32_t main()
{
	Init;
	Solution();
	return 0;
}

int dfs(int v){
	mark[v] = 1;
	int sub = 1;
	for(int neib : adj[v]){
		if(mark[neib])
			continue;
		sub += dfs(neib);
	}
	if(sub%2 == 0)
		++ans;
	return sub;
}

inline void Solution(){
	cin >> n;
	forar(i,n-1){
		int a,b;
		cin >> a >> b;
		adj[--a].pb(--b);
		adj[b].pb(a);
	}
	if(n%2){
		cout << -1 << endl;
		return;
	}
	dfs(0);
	cout << ans-1 << endl;
}
