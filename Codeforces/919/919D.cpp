//In The Name of Allah
//Wed 11/11/96
#pragma GCC optimize "-O3"
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

const ll mod = 1e9+7,M = 3e5+100;

void Solution();

int n,m;
int nme[M];
vector<int> adjout[M],adjin[M];
bool mark[M];
bool ispar[M];
int dp[M][30];
bool isdag = true;

int main()
{
	Init;
	Solution();
	return 0;
}

void dfs(int v){
	isdag &= !ispar[v];
	if(mark[v])
		return;
	mark[v] = ispar[v] = 1;
	for(int neib : adjout[v])
		dfs(neib);
	ispar[v] = 0;
}

void getdp(int v){
	if(mark[v])
		return;
	mark[v] = 1;
	for(int neib : adjout[v]){
		getdp(neib);
		forar(i,27){
			dp[v][i] = max(dp[v][i],dp[neib][i]);
		}
	}
	dp[v][nme[v]]++;
}

inline void Solution(){
	cin >> n >> m;
	forar(i,n){
		char c;
		cin >> c;
		nme[i] = c-'a';
	}
	forar(i,m){
		int a,b;
		cin >> a >> b;
		adjout[--a].pb(--b);
		adjin[b].pb(a);
	}
	forar(i,n){
		dfs(i);
	}
	if(!isdag){
		cout << -1 << endl;
		return;
	}
	fill(mark,mark+n,0);
	int ans = 0;
	forar(i,n){
		getdp(i);
		forar(j,27){
			ans = max(ans,dp[i][j]);
		}
	}
	cout << ans << endl;
}
