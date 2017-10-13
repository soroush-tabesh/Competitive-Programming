/*
ID: soroosh4
LANG: C++11
TASK: castle
*/
//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("castle.in","r",stdin),freopen("castle.out","w",stdout)
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

pii box[51][51]; // walls and room
bool mark[51][51];
pii maxareawall; char sideofwall = 'N';
map<int,vector<pii > > rooms;
int m,n,room,maxarea,maxarea2;

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

void dfs(int vi,int vj){
	if(vi < 0 || vj < 0 || vi >= n || vj >= m)
		return;
	if(mark[vi][vj])
		return;
	mark[vi][vj] = true;
	box[vi][vj].S = room;
	rooms[room].pb({vi,vj});
	if(~box[vi][vj].F & (1 << 0)) // west
		dfs(vi,vj-1);
	if(~box[vi][vj].F & (1 << 1))// north
		dfs(vi-1,vj);
	if(~box[vi][vj].F & (1 << 2)) // east
		dfs(vi,vj+1);
	if(~box[vi][vj].F & (1 << 3)) // south
		dfs(vi+1,vj);
}

void Solution(){
	cin >> m >> n;
	forar(i,n)
		forar(j,m)
			cin >> box[i][j].F;
	// assign room numbers
	forar(i,n){
		forar(j,m){
			if(!mark[i][j]){
				room++;
				dfs(i,j);
			}
		}
	}
	// find maxsize room
	for(pair<int,vector<pair<int,int> > > inside : rooms){
		maxarea = max(maxarea,int(inside.S.size()));
	}
	// find those biggies !!!!
	forar(i,n){
		forar(j,m){
			if(i>0){//check north
				if(box[i][j].S != box[i-1][j].S){
					if(maxarea2 < rooms[box[i][j].S].size()+rooms[box[i-1][j].S].size()){
						maxarea2 = rooms[box[i][j].S].size()+rooms[box[i-1][j].S].size();
					}else if(maxarea2 < rooms[box[i][j].S].size()+rooms[box[i-1][j].S].size()){
					}
				}
			}
			if(j>0){//check west
				if(box[i][j].S != box[i][j-1].S){
					if(maxarea2 < rooms[box[i][j].S].size()+rooms[box[i][j-1].S].size()){
						maxarea2 = rooms[box[i][j].S].size()+rooms[box[i][j-1].S].size();
					}else if(maxarea2 < rooms[box[i][j].S].size()+rooms[box[i][j-1].S].size()){
					}
				}
			}
			if(i < n-1){//check south
				if(box[i][j].S != box[i+1][j].S){
					if(maxarea2 < rooms[box[i][j].S].size()+rooms[box[i+1][j].S].size()){
						maxarea2 = rooms[box[i][j].S].size()+rooms[box[i+1][j].S].size();
					}else if(maxarea2 < rooms[box[i][j].S].size()+rooms[box[i+1][j].S].size()){
					}
				}
			}
			if(j < m-1){//check east
				if(box[i][j].S != box[i][j+1].S){
					if(maxarea2 < rooms[box[i][j].S].size()+rooms[box[i][j+1].S].size()){
						maxarea2 = rooms[box[i][j].S].size()+rooms[box[i][j+1].S].size();
					}else if(maxarea2 < rooms[box[i][j].S].size()+rooms[box[i][j+1].S].size()){
					}
				}
			}
		}
	}
	// now try to find that tiny room!
	maxareawall = {0,m-1};
	forar(i,n){
		forar(j,m){
			pii mdl = {i,j};
			if(rooms[box[(mdl.F-1 >= 0 ? mdl.F-1 : 0)][mdl.S].S].size() + rooms[box[mdl.F][mdl.S].S].size() == maxarea2 
				&& box[(mdl.F-1 >= 0 ? mdl.F-1 : 0)][mdl.S].S != box[mdl.F][mdl.S].S
				&& (maxareawall.S > mdl.S || (maxareawall.S == mdl.S && maxareawall.F < mdl.F))){
				maxareawall = mdl;
				sideofwall = 'N';
			}
			if(rooms[box[mdl.F][(mdl.S-1 >= 0 ? mdl.S-1 : 0)].S].size() + rooms[box[mdl.F][mdl.S].S].size() == maxarea2 
				&& box[mdl.F][(mdl.S-1 >= 0 ? mdl.S-1 : 0)].S != box[mdl.F][mdl.S].S
				&& (maxareawall.S > mdl.S || (maxareawall.S == mdl.S && maxareawall.F < mdl.F))){
				maxareawall = mdl;
				sideofwall = 'W';
			}
			if(rooms[box[(mdl.F+1 < n ? mdl.F+1 : n-1)][mdl.S].S].size() + rooms[box[mdl.F][mdl.S].S].size() == maxarea2 
				&& box[(mdl.F+1 < n ? mdl.F+1 : n-1)][mdl.S].S != box[mdl.F][mdl.S].S
				&& (maxareawall.S > mdl.S || (maxareawall.S == mdl.S && maxareawall.F < mdl.F))){
				maxareawall = mdl;
				sideofwall = 'S';
			}
			if(rooms[box[mdl.F][(mdl.S+1 < m ? mdl.S+1 : m-1)].S].size() + rooms[box[mdl.F][mdl.S].S].size() == maxarea2
				&& box[mdl.F][(mdl.S+1 < m ? mdl.S+1 : m-1)].S != box[mdl.F][mdl.S].S
				&& (maxareawall.S > mdl.S || (maxareawall.S == mdl.S && maxareawall.F < mdl.F))){
				maxareawall = mdl;
				sideofwall = 'E';
			}
		}
	}
	
	//finally the result
	cout << room << endl;
	cout << maxarea << endl;
	cout << maxarea2 << endl;
	cout << maxareawall.F+1 << ' ' << maxareawall.S+1 << ' ' << sideofwall << endl;
	
}
