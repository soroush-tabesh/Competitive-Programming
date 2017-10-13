//In The Name of Allah
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define pf push_front

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7;

void Solution();

ll n;
vector<int> adj[100*1000+5];
bool mark[100*1000+5];
ld pexp;

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

void dfs(int v,ld prob,int dist){
	mark[v] = 1;
	bool is = false;
	int cnt = 0;
	for(int neib : adj[v]){
		if(!mark[neib]){
			cnt++;
		}
	}
	for(int neib : adj[v]){
		if(!mark[neib]){
			dfs(neib,prob/((long double)cnt),dist+1);
			is = true;
		}
	}
	if(!is){
		pexp += ((long double)dist)*prob;
	}
}

void Solution(){
	cin >> n;
	forar(i,n-1){
		ll a,b;
		cin >> a >> b;
		adj[--a].pb(--b);
		adj[b].pb(a);
	}
	dfs(0,1,0);
	cout << fixed;
	cout.precision(15);
	cout << pexp;
}