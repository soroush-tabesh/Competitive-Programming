//In The Name of Allah
//Sun 26/9/96
// *** INCOMPLETE :( (due to FATIGUE!!!)
// IDEA : use path compression to do binary search and reducing O(n^2) to O(n)
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("piepie.in","r",stdin),freopen("piepie.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define clamp(a,b,i) max(min(i,b),a)
#define infint 1000*1000*1000

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+100;

void Solution();

int n,d;
pii besbyels[M],elsbybes[M];
int dist[2][M];
int nxt[2][M];
bool mark[2][M];

int main()
{
	Init;
	WFile;
	Solution();
	return 0;
}

int find_next(int i,int j){
	if(mark[i][nxt[i][j]])
		nxt[i][j] = find_next(i,nxt[i][j]);
	return nxt[i][j];
}

bool compf(pii a,pii b){
	return ((a.F < b.F)||(a.F == b.F && a.S < b.S));
}

bool compf(pii a,pii b){
	return ((a.S < b.S)||(a.S == b.S && a.F < b.F));
}

void Solution(){
	cin >> n >> d;
	forar(i,n){
		cin >> besbyels[i].F >> besbyels[i].S;
	}
	forar(i,n){
		cin >> elsbybes[i].F >> elsbybes[i].S;
	}
	sort(elsbybes,elsbybes+n,comp1);
	sort(besbyels,besbyels+n,comp2);
	forar(i,2){
		forar(j,n){
			dist[i][j] = infint;
			nxt[i][j] = j+1;
		}
	}
	{
		vector<int> bespr,elspr;
		int bpr=0,epr=0;
		forar(i,n){
			if(besbyels[i].S == 0){
				dist[0][i] = 0;
				bespr.pb(i);
			}
		}
		while(bpr < bespr.size()){
			while(bpr < bespr.size()){
				int indl = lower_bound(elsbybes,elsbybes+n,mp(besbyels[bespr[bpr]].F-d,0),comp2);
				int indr = upper_bound(elsbybes,elsbybes+n,bespr[bpr]);
				while(indl < indr){
					elspr.pb(indl);
					mark[1][indl] = 1;
					dist[1][indl] = min(dist[1][indl],dist[0][bpr]+1);
					indl=find_next(1,indl);
				}
				bpr++;
			}
			while(epr < elspr.size()){
				int indl = lower_bound(besbyels,besbyels+n,elspr[epr]-d);
				int indr = upper_bound(besbyels,besbyels+n,elspr[epr]);
				while(indl < indr){
					bespr.pb(indl);
					mark[0][indl] = 1;
					dist[0][indl] = min(dist[0][indl],dist[1][epr]+1);
					indl=find_next(0,indl);
				}
				epr++;
			}
		}
	}
}
