//In The Name of Allah
//Wed 29/9/96
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

const ll mod = 1e9+7,M = 2e3+100;

void Solution();

int n,m,q;
vector<int> adj[M];
vector<int> badj[M];
int low[M],pre[M],brd,cnt,comp[M],cmpcnt;

int main()
{
	Init;
	Solution();
	return 0;
}

void dfs(int u, int v){
	pre[v] = cnt++;
	low[v] = pre[v];
	for(int w : adj[v]){
		if(pre[w] == -1){
			dfs(v,w);
			low[v] = min(low[v],low[w]);
			if(low[w] == pre[w]){
				brd++;
				badj[v].pb(w);
				badj[w].pb(v);
			}
			
		}else if(w != u){
			low[v] = min(low[v],low[w]);
		}
	}
}

void flood(int v){
	comp[v] = cmpcnt;
	for(int neib : badj[v]){
		if(!comp[neib]){
			flood(neib);
		}
	}
}

void Solution(){
	cin >> n >> m >> q;
	forar(i,m){
		int a,b;
		cin >> a >> b;
		adj[--a].pb(--b);
		adj[b].pb(a);
	}
	forar(i,n){
		pre[i] = low[i] = -1;
	}
	forar(i,n){
		if(pre[i] == -1)
			dfs(i,i);
	}
	forar(i,n){
		if(!comp[i]){
			cmpcnt++;
			flood(i);
		}
	}
	forar(i,q){
		int a,b;
		cin >> a >> b;
		if(comp[a-1] == comp[b-1]){
			cout << 1 << endl;
		}else{
			cout << 0 << endl;
		}
	}
	
}
