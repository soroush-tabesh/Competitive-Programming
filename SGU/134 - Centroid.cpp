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
vector<ll> adj[16005];
bool mark[16005];
ll dist[16005];
ll children[16005];
ll f[16005];
ll parent[16005];
vector<ll> topro;ll topro_start = 0,topro_end = 0;
vector<ll> ans;
ll centerval = 20*1000;

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
	mark[v] = 1;
	parent[v] = -1;
	topro.pb(v);
	topro_end++;
	while(topro_start < topro_end){
		ll cur = topro[topro_start];
		topro_start++;
		for(ll neib : adj[cur]){
			if(!mark[neib]){
				mark[neib] = 1;
				dist[neib] = dist[cur]+1;
				parent[neib] = cur;
				topro.pb(neib);
				topro_end++;
			}
		}
	}
}

void revbfs(){
	while(!topro.empty()){
		ll cur = topro.back();
		topro.pop_back();
		if(parent[cur] != -1){
			children[parent[cur]] += children[cur] + 1;
		}
	}
}

void centroid(){
	forar(i,n){
		for(ll neib : adj[i]){
			if(parent[i] == neib)
				continue;
			f[i] = max(children[neib]+1,f[i]);
		}
		f[i] = max(f[i],n-(children[i]+1));
		centerval = min(centerval,f[i]);
	}
	forar(i,n){
		if(f[i] == centerval){
			ans.pb(i);
		}
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
	
	bfs(0);
	revbfs();
	centroid();
	
	cout << centerval << " " << ans.size() << endl;
	forar(i,ans.size()){
		if(i)
			cout << " ";
		cout << ans[i]+1;
	}
	cout << endl;
}