//In The Name of Allah
//Wed 12/7/96
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

const ll mod = 1e9+7,M = 2e5+5;

void Solution();

int n,q;
vector<int> child[2005];
int dp[15][2005];
const int mlg = 12;
int h[2005];

int main()
{
	Init;
	//WFile;
	Solution();
	return 0;
}

void dfs(int v,int dep){
	h[v] = dep;
	for(int neib : child[v])
		dfs(neib,dep+1);
}

void prep(){
	dfs(0,0);
	fori(j,1,mlg+1){
		forar(i,n){
			dp[j][i] = dp[j-1][dp[j-1][i]];
		}
	}
}

int query(int v,int u){
	if(h[v] < h[u])
		swap(u,v);
	for(int j = mlg;j >= 0;j--)
		if(h[dp[j][v]] >= h[u])
			v = dp[j][v];
	if(v == u)
		return v;
	for(int j = mlg;j >= 0;j--){
		if(dp[j][v] != dp[j][u]){
			v = dp[j][v];
			u = dp[j][u];
		}
	}
	return dp[0][v];
}

void Solution(){
	int tst;
	cin >> tst;
	fori(tstt,1,tst+1){
		cout << "Case " << tstt << ":" << endl;
		cin >> n;
		forar(i,n){
			child[i].clear();
		}
		forar(i,n){
			int m,a;
			cin >> m;
			forar(j,m){
				cin >> a;
				child[i].pb(--a);
				dp[0][a] = i;
			}
		}
		prep();
		cin >> q;
		forar(i,q){
			int a,b;
			cin >> a >> b;
			cout << query(a-1,b-1)+1 << endl;
		}
	}
}
