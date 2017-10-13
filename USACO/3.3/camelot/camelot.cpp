//In The Name of God
/*
ID: soroosh4
LANG: C++11
TASK: camelot
*/
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("camelot.in","r",stdin),freopen("camelot.out","w",stdout)
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

// row , column format
int dists[31][27][31][27]; // tar , cell : with knight-like move
bool mark[31][27][31][27]; // bfs mark for each target and each cell
vector<pii> topro; // bfs current process queue
vector<pii> tnpro; // bfs next process queue

pii king; // king pos
vector<pii> knights; // knights pos
pii board; // board size
const int inf = 1e9;
pii ways[8] = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
pii kingcheck[25];

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

int getkingmovecost(int w){
	return max(abs(kingcheck[w].F),abs(kingcheck[w].S));
}

void Solution(){
	// input
	cin >> board.F >> board.S;
	char tmc;
	int tmr;
	cin >> tmc;
	king.S = int(tmc-'A');
	cin >> king.F;
	king.F--;
	string s;
	getline(cin,s);
	while(getline(cin,s)){
		stringstream ss(s);
		while(ss.tellg() != -1){
			ss >> tmc;
			ss >> tmr;
			knights.pb({tmr-1,int(tmc-'A')});
		}
	}
	
	// init
	forar(i,5){
		forar(j,5){
			kingcheck[i*5+j] = {2-i,2-j};
		}
	}
	
	
	// run BFS SPA on each start point
	forar(tari,board.F){
		forar(tarj,board.S){
			// init bfs
			mark[tari][tarj][tari][tarj] = 1;
			forar(i,board.F){
				forar(j,board.S){
					dists[tari][tarj][i][j] = inf;
				}
			}
			dists[tari][tarj][tari][tarj] = 0;
			tnpro.pb({tari,tarj});
			
			// run bfs
			while(!tnpro.empty()){
				swap(tnpro,topro);
				tnpro.clear();
				for(pii v : topro){
					forar(w,8){
						pii neib = v;
						neib.F += ways[w].F;
						neib.S += ways[w].S;
						if(neib.F >= board.F || neib.F < 0 || neib.S >= board.S || neib.S < 0)
							continue;
						if(!mark[tari][tarj][neib.F][neib.S]){
							mark[tari][tarj][neib.F][neib.S] = 1;
							dists[tari][tarj][neib.F][neib.S] = dists[tari][tarj][v.F][v.S] + 1;
							tnpro.pb(neib);
						}
					}
				}
			}
		}
	}
	
	// find answer
	int res = inf;
	forar(tari,board.F){
		forar(tarj,board.S){
			int restemp = 0;
			for(pii kn : knights){
				restemp += dists[tari][tarj][kn.F][kn.S];
			}
			for(pii kn : knights){
				restemp -= dists[tari][tarj][kn.F][kn.S];
				forar(w,25){
					if(king.F+kingcheck[w].F < board.F && king.F+kingcheck[w].F >= 0 && king.S+kingcheck[w].S < board.S && king.S+kingcheck[w].S >= 0
					&& dists[king.F+kingcheck[w].F][king.S+kingcheck[w].S][kn.F][kn.S] != inf && dists[king.F+kingcheck[w].F][king.S+kingcheck[w].S][tari][tarj] != inf)
						res = min(res,restemp + dists[king.F+kingcheck[w].F][king.S+kingcheck[w].S][kn.F][kn.S] + dists[king.F+kingcheck[w].F][king.S+kingcheck[w].S][tari][tarj]+getkingmovecost(w));
				}
				restemp += dists[tari][tarj][kn.F][kn.S];
			}
			if(knights.empty()){
				res = min(res,max(abs(tari - king.F),abs(tarj - king.S)));
			}
		}
	}
	cout << res << endl;
}
