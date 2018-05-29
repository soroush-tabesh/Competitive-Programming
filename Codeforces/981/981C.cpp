//In The Name of Allah
//Thu 6/3/97
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

int n;
vector<int> adj[M];
bool mark[M];
bool flag = false;
int cent;
bool res = true;
vector<int> leaf;

int32_t main()
{
	Init;
	Solution();
	return 0;
}

void dfs(int v){
	if(mark[v])
		return;
	mark[v] = 1;
	if(adj[v].size() > 2){
		if(!flag){
			flag = true;
			cent = v;
		}else{
			res = false;
		}
		return;
	}
	for(int neib : adj[v]){
		dfs(neib);
	}
}

inline void Solution(){
	cin >> n;
	forar(i,n-1){
		int a,b;
		cin >> a >> b;
		adj[--a].pb(--b);
		adj[b].pb(a);
	}
	forar(i,n){
		if(adj[i].size() == 1){
			dfs(i);
			leaf.pb(i);
		}
	}
	cout << (res ? "Yes" : "No") << endl;
	if(res){
		if(leaf.size() == 2){
			cout << 1 << endl;
			cout << leaf[0] + 1 << ' ' << leaf[1] + 1 << endl;
		}else{
			cout << leaf.size() << endl;
			for(int x : leaf){
				cout << cent + 1 << ' ' << x + 1 << endl;
			}
		}
	}
}
