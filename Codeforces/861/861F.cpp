//In The Name of Allah
//Sun 26/6/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
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

int n,m;
set<int> adj[M];
int mark[M]; int mcnt = 0;
int mark2[M];

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

int dfs(int v){
	mark[v] = mcnt;
	int res = 1;
	for(int neib : adj[v]){
		if(mark[neib] != mcnt){
			res += dfs(v);
		}
	}
	for(set<int>::iterator it = adj[v].begin();it != adj[v].end();it++){
		if(adj[v].size() == 1 && mark2[*(adj[v].begin())] != mcnt){
			mark2[v] = mcnt;
			break;
		}
	}
	return res;
}

void Solution(){
	cin >> n >> m;
	forar(i,m){
		int a,b;
		cin >> a >> b;
		adj[--a].pb(--b);
		adj[b].pb(a);
	}
	bool change = true;
	while(change){
		change = false;
		forar(i,n){
			mcnt++;
			if(dfs(i)>=3){
				change = true;
			}
		}
	}
}
