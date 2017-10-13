//In The Name of Allah
//Sat 4/6/96
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

const ll mod = 1e9+7,MX = 1000;

void Solution();

int n,m;
char data[MX][MX];
set<pii> nextI[MX][MX];
set<pii> adj[MX][MX];
bool permanent[MX][MX];
bool temporary[MX][MX];
pii ways[4] = {{1,0},{0,1},{-1,0},{0,-1}};
bool isdag = true;
bool isnull = true;
int dp[MX][MX];
bool mark[MX][MX];
int ans;

int main()
{
	Init;
	//WFile
	Solution();
	return 0;
}

void findI(pii pos,int seq,pii beg){ // around pos,search for wanted seq
	if(pos.F < 0 || pos.F >= n || pos.S < 0 || pos.S >= m || data[pos.F][pos.S] != "EYDI"[seq])
		return;
	if(seq == 3){
		nextI[beg.F][beg.S].insert(pos);
		return;
	}
	forar(w,4){
		findI({pos.F+ways[w].F,pos.S+ways[w].S},seq+1,beg);
	}
}

void checkisdag(pii v){
	permanent[v.F][v.S] = 1;
	temporary[v.F][v.S] = 1;
	for(pii neib : adj[v.F][v.S]){
		if(temporary[neib.F][neib.S]){
			isdag = false;
		}
		if(permanent[neib.F][neib.S])
			continue;
		checkisdag(neib);
	}
	temporary[v.F][v.S] = 0;
}

int getfurthest(pii v){
	if(mark[v.F][v.S])
		return dp[v.F][v.S];
	mark[v.F][v.S] = 1;
	for(pii neib : adj[v.F][v.S]){
		dp[v.F][v.S] = max(dp[v.F][v.S],getfurthest(neib)+1);
	}
	return dp[v.F][v.S];
}

void Solution(){
	cin >> n >> m;
	forar(i,n){
		forar(j,m){
			cin >> data[i][j];
		}
	}
	// fill nextI
	forar(i,n){
		forar(j,m){
			if(data[i][j] == 'E'){
				findI({i,j},0,{i,j});
			}
		}
	}
	// find adj
	forar(i,n){
		forar(j,m){
			if(nextI[i][j].empty())
				continue;
			isnull = false;
			for(pii x : nextI[i][j]){
				forar(w,4){
					if(!nextI[x.F+ways[w].F][x.S+ways[w].S].empty()){
						adj[i][j].insert({x.F+ways[w].F,x.S+ways[w].S});
					}
				}
			}
		}
	}
	// do topological sort
	forar(i,n){
		forar(j,m){
			if(nextI[i][j].empty() || permanent[i][j])
				continue;
			checkisdag({i,j});
		}
	}
	if(isnull){
		cout << "Poor Mobin!" << endl;
		return;
	}
	if(!isdag){
		cout << "Poor Uncle!" << endl;
		return;
	}
	// find answer
	forar(i,n){
		forar(j,m){
			if(nextI[i][j].empty())
				continue;
			ans = max(ans,getfurthest({i,j}));
		}
	}
	cout << ans+1 << endl;
	
}

