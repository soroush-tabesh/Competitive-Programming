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

vector<ll> adj[100*1000+5];
ll dist[100*1000+5];
ll n,q;

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

void dfs(ll v,ll d){
	dist[v] = d;
	for(ll neib : adj[v]){
		if(!dist[neib] && neib != 0)
			dfs(neib,d+1);
	}
}

void Solution(){
	cin >> n >> q;
	fori(i,1,n){
		ll a;
		cin >> a;
		a--;
		adj[i].pb(a);
		adj[a].pb(i);
	}
	dfs(0,0);
	while(q--){
		
	}
}