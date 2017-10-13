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

queue<ll> topro;
bool mark[100];
vector<ll> adj[100];
vector<ll> sol;
ll dist[100];
ll n,x,e;

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

void bfs(ll v){
	topro.push(v);
	mark[v] = 1;
	while(!topro.empty()){
		ll cur = topro.front();
		for(ll neib : adj[cur]){
			if(!mark[neib]){
				mark[neib] = 1;
				dist[neib] = dist[cur] + 1;
				if(dist[neib] == 2){
					sol.pb(neib);
				}
				topro.push(neib);
			}
		}
		topro.pop();
	}
}

void Solution(){
	cin >> n >> e;
	forar(i,e){
		ll a,b;
		cin >> a >> b;
		adj[--a].pb(--b);
		adj[b].pb(a);
	}
	cin >> x;
	bfs(--x);
	sort(sol.begin(),sol.end());
	cout << sol.size() << endl;
	for(ll k : sol){
		cout << k+1 << " ";
	}
}