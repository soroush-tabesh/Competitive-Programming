/*
ID: soroosh4
LANG: C++11
TASK: maze1
*/
//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("maze1.in","r",stdin),freopen("maze1.out","w",stdout)
#define forar(i,n) for(int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
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
const int M = 100*1000+5;

void Solution();

int w,h;
const int inf = 10000;
string mp[210];
vector<pii> adj[105][40];
int resdist[105][40];

//dijkstra data

int dist[105][40];
bool mark[105][40];
set<pii> exs;

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

void Solution(){
	cin >> w >> h;
	memset(resdist,inf,sizeof resdist);
	getline(cin,mp[0]);
	forar(i,2*h+1){
		getline(cin,mp[i]);
	}
	
	forar(i,h){
		forar(j,w){
			int curi = 2*i+1;
			int curj = 2*j+1;
			//set neibs
			if(mp[curi+1][curj] == ' '){
				if(i == h-1){
					exs.insert({i,j});
				}else{
					adj[i][j].pb({i+1,j});
				}
			}
			if(mp[curi-1][curj] == ' '){
				if(i == 0){
					exs.insert({i,j});
				}else{
					adj[i][j].pb({i-1,j});
				}
			}
			if(mp[curi][curj+1] == ' '){
				if(j == w-1){
					exs.insert({i,j});
				}else{
					adj[i][j].pb({i,j+1});
				}
			}
			if(mp[curi][curj-1] == ' '){
				if(j == 0){
					exs.insert({i,j});
				}else{
					adj[i][j].pb({i,j-1});
				}
			}
		}
	}
	
	//run dijkstra to find worst
	int worst = 0;
	for(pii e : exs){
		//init
		memset(mark,0,sizeof mark);
		memset(dist,inf,sizeof dist);
		mark[e.F][e.S] = 1;
		dist[e.F][e.S] = 0;
		for(pii neib : adj[e.F][e.S]){
			dist[neib.F][neib.S] = min(dist[neib.F][neib.S],dist[e.F][e.S]+1);
		}
		
		//algorithm
		int prc = 0;
		while(prc < w*h){
			pii neib = {0,0};
			bool is = false;
			forar(i,h){
				forar(j,w){
					if(!is && !mark[i][j]){
						is = true;
						neib.F = i;
						neib.S = j;
					}
					if(dist[i][j] < dist[neib.F][neib.S] && !mark[i][j]){
						neib.F = i;
						neib.S = j;
					}
				}
			}
			mark[neib.F][neib.S] = 1;
			prc++;
			for(pii upd : adj[neib.F][neib.S]){
				if(mark[upd.F][upd.S])
					continue;
				dist[upd.F][upd.S] = min(dist[upd.F][upd.S],dist[neib.F][neib.S]+1);
			}
		}
		
		//find worst
		forar(i,h){
			forar(j,w){
				resdist[i][j] = min(resdist[i][j],dist[i][j]+1);
			}
		}
	}
	forar(i,h){
		forar(j,w){
			worst = max(resdist[i][j],worst);
		}
	}
	
	cout << worst << endl;
	
}
