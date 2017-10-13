//In The Name of Allah
//Sun 9/7/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cerr << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 3e5+5;

void Solution();

int n,m;
vector<pii> adj[M];
int odd[M];
int ocnt;
int neutcnt;
vector<int> ans;
bool mark[M];

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

bool dfs(int v){
	if(mark[v])
		return false;
	else
		mark[v] = 1;
	bool res = (odd[v]==1);
	for(pii neib : adj[v]){
		bool is = dfs(neib.F);
		res ^= is;
		if(is)
			ans.pb(neib.S);
	}
	return res;
}

void Solution(){
	cin >> n >> m;
	ans.reserve(n);
	forar(i,n){
		cin >> odd[i];
		if(odd[i] == 1)
			ocnt++;
		else if(odd[i] == -1)
			neutcnt++;
	}
	if(ocnt % 2 == 1){
		if(neutcnt == 0){
			cout << -1 << endl;
			return;
		}else{
			forar(i,n){
				if(odd[i] == -1){
					odd[i] = 1;
					break;
				}
			}
		}
	}
	forar(i,m){
		int a,b;
		cin >> a >> b;
		adj[--a].pb({--b,i});
		adj[b].pb({a,i});
	}
	dfs(0);
	cout << ans.size() << endl;
	for(int x : ans){
		cout << x << endl;
	}
}
