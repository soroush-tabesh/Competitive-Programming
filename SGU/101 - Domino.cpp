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

short n;
short adj[7][7];
vector<pair<short,bool> > adjList[7][7];
short ov2c,ov2;
vector<short> ans;

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

void dfs(short v){
	for(short neib = 0;neib < 7;neib++){
		while(adj[v][neib]){
			adj[v][neib]--;
			adj[neib][v]--;
			dfs(neib);
		}
	}
	ans.pb(v);
}

void Solution(){
	cin >> n;
	for(short i = 1;i <= n;i++){
		short a,b;
		cin >> a >> b;
		adj[a][b]++;
		adj[b][a]++;
		adjList[a][b].pb({i,0});
		adjList[b][a].pb({i,1});
	}
	for(short i = 0;i < 7;i++){
		short cnt = 0;
		for(short j = 0;j < 7;j++){
			cnt += adj[i][j];
		}
		if(cnt%2 == 1){
			ov2c++;
			ov2 = i;
		}
	}
	
	if(ov2c != 2 && ov2c != 0){
		cout << "No solution" << endl;
		return;
	}
	
	if(ov2c == 0){
		for(short i = 0;i < 7;i++){
			short cnt = 0;
			for(short j = 0;j < 7;j++){
				cnt += adj[i][j];
			}
			if(cnt){
				ov2 = i;
				break;
			}
		}
	}
	
	dfs(ov2);
	
	for(short i = 0;i < 7;i++){
		short cnt = 0;
		for(short j = 0;j < 7;j++){
			cnt += adj[i][j];
		}
		if(cnt){
			cout << "No solution" << endl;
			return;
		}
	}
	
	for(short i = 0;i < ans.size();i++){
		if(i){
			pair<short,bool> t = adjList[ans[i-1]][ans[i]].back();
			adjList[ans[i-1]][ans[i]].pop_back();
			for(short j = 0;j < adjList[ans[i]][ans[i-1]].size();j++){
				if(adjList[ans[i]][ans[i-1]][j].F == t.F){
					adjList[ans[i]][ans[i-1]].erase(adjList[ans[i]][ans[i-1]].begin() + j);
					break;
				}
			}
			cout << t.F << (t.S ? " -" : " +") << endl;
		}
	}
}

