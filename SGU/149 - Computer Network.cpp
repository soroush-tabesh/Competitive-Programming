//In The Name of Allah
//Mon 23/5/96
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
vector<pii> adj[10*1000+5];
bool mark[10*1000+5];
int dist[10*1000+5];
int diamA,diamB,dat;
int fur[10*1000+5];

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

void findfurthest_dfs(int v,int d){
	mark[v] = 1;
	dist[v] = d;
	for(pii neib : adj[v]){
		if(mark[neib.F])
			continue;
		findfurthest_dfs(neib.F,d+neib.S);
	}
}

pii findfurthest(int v){
	int resd = 0;
	int resv = v;
	forar(i,n){
		mark[i] = 0;
		dist[i] = 0;
	}
	findfurthest_dfs(v,0);
	forar(i,n){
		fur[i] = max(fur[i],dist[i]);
		if(dist[i] > resd){
			resd = dist[i];
			resv = i;
		}
	}
	return {resv,resd};
}

void Solution(){
	cin >> n;
	fori(i,1,n){
		int a,b;
		cin >> a >> b;
		a--;
		adj[i].pb({a,b});
		adj[a].pb({i,b});
		fur[i] = fur[a]+b;
		if(fur[i] > dat){
			dat = fur[i];
			diamA = i;
		}
	}
	diamB = findfurthest(diamA).F;
	findfurthest(diamB);
	forar(i,n){
		cout << fur[i] << endl;
	}
}

