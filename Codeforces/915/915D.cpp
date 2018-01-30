//In The Name of Allah
//Sat 23/10/96
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

int n,m,ans;
vector<int> adj[1000];
bool mark[1000],ispar[1000];

int main()
{
	Init;
	Solution();
	return 0;
}

void dfs(int v){
	mark[v] = ispar[v] = 1;
	for(int neib : adj[v]){
		if(mark[neib]){
			ans += ispar[neib];
		}
	}
	ispar[v] = 0;
}

void Solution(){
	cin >> n >> m;
	forar(i,m){
		int a,b;
		cin >> a >> b;
		--a,--b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(0);
	if(ans <= n)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
