//In The Name of Allah
//Mon 30/5/96
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

const ll inf = 1e18;
ll n,m;
ll adj[105][105];
ll ans[105];
set<ll> nextVert[105][105];

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

void pathMark(ll cur,ll last){
	for(ll x : nextVert[cur][last]){
		if(x == last)
			continue;
		ans[x]++;
		pathMark(x,last);
	}
}

void Solution(){
	cin >> n >> m;
	forar(i,n){
		forar(j,n){
			if(i!=j)
				adj[i][j] = inf;
		}
	}
	forar(i,m){
		ll a,b,w;
		cin >> a >> b >> w;
		adj[--a][--b] = w;
		nextVert[a][b].insert(b);
	}
	// run WFI
	forar(k,n){
		forar(i,n){
			forar(j,n){
				if(adj[i][k]+adj[k][j] < adj[i][j]){
					adj[i][j] = adj[i][k]+adj[k][j];
					nextVert[i][j].clear();
					nextVert[i][j].insert(nextVert[i][k].begin(),nextVert[i][k].end());
				}else if(adj[i][k]+adj[k][j] == adj[i][j]){
					nextVert[i][j].insert(nextVert[i][k].begin(),nextVert[i][k].end());
				}
			}
		}
	}
	forar(i,n){
		forar(j,n){
			pathMark(i,j);
		}
	}
	forar(i,n){
		cout << ans[i] << endl;
	}
}

