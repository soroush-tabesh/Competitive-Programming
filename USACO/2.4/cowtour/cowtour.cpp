/*
ID: soroosh4
LANG: C++11
TASK: cowtour
*/
//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define WFile freopen("cowtour.in","r",stdin),freopen("cowtour.out","w",stdout)
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

const double inf = 1e9;
int n;
pair<double,double> cords[155];  // every coords in x,y format
bool mark[155];                  // is it visited ?
bool adj[155][155];              // is vert i adjacent to j ?
map<int,vector<int> > adjlist;   // adjancy list
int fldnum[155];                 // field id for every vert
double dists[155][155];          // pre-calculation and main array for Floyd-Warshall
vector<vector<int> > fields;     // data for each field
double eccents[155];             // eccentrity of each vertex
double diams[155];               // diameter of a field

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

void flood(int v){
	mark[v] = 1;
	fldnum[v] = fields.size()-1;
	fields.back().pb(v);
	for(int i : adjlist[v]){
		if(!mark[i]){
			flood(i);
		}
	}
}

void Solution(){
	cout.precision(6);
	cout << fixed;
	cin >> n;
	forar(i,n){
		double a,b;
		cin >> a >> b;
		cords[i] = {a,b};
	}
	forar(i,n){
		forar(j,n){
			char c;
			cin >> c;
			if(c == '1'){
				adj[i][j] = 1;
				adjlist[i].pb(j);
				dists[i][j] = sqrt((cords[i].F - cords[j].F)*(cords[i].F - cords[j].F) + (cords[i].S - cords[j].S)*(cords[i].S - cords[j].S));
			}else if(i != j){
				dists[i][j] = inf;
			}
		}
	}
	
	// run flood-fill to determine components
	forar(i,n){
		if(!mark[i]){
			vector<int> newfld;
			fields.pb(newfld);
			flood(i);
		}
	}
	
	// run Floyd-Warshall for each field
	forar(a,fields.size()){
		// algorithm
		forar(k,fields[a].size()){
			forar(i,fields[a].size()){
				forar(j,fields[a].size()){
					if(dists[fields[a][i]][fields[a][j]] > dists[fields[a][i]][fields[a][k]] + dists[fields[a][k]][fields[a][j]]){
						dists[fields[a][i]][fields[a][j]] = dists[fields[a][i]][fields[a][k]] + dists[fields[a][k]][fields[a][j]];
					}
				}
			}
		}
		
		// find eccentrity
		forar(i,fields[a].size()){
			double eccen = 0;
			forar(j,fields[a].size()){
				eccen = max(eccen,dists[fields[a][i]][fields[a][j]]);
				diams[a] = max(diams[a],dists[fields[a][i]][fields[a][j]]);
			}
			eccents[fields[a][i]] = eccen;
		}
	}
	
	double ans = inf;
	// match two center
	forar(vi,n){
		fori(vj,vi+1,n){
			if(fldnum[vi] == fldnum[vj])
				continue;
			double distvivj = sqrt((cords[vi].F - cords[vj].F)*(cords[vi].F - cords[vj].F) + (cords[vi].S - cords[vj].S)*(cords[vi].S - cords[vj].S));
			ans = min(ans,max(distvivj + eccents[vi] + eccents[vj],max(diams[fldnum[vi]],diams[fldnum[vj]])));
		}
	}
	cout << ans << endl;
}
