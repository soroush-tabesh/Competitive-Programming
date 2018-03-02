//In The Name of Allah
//Fri 12/12/96
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

const ll mod = 1e9+7,M = 2e5+100;

void Solution();

int n,m,x,y,z;
ll adja[510][510],adjb[510][510];

int main()
{
	Init;
	Solution();
	return 0;
}

inline void Solution(){
	cin >> n >> m >> x >> y >> z;
	forar(i,n){
		forar(j,n){
			if(i!=j)
				adja[i][j] = adjb[i][j] = mod * mod;
		}
	}
	forar(i,m){
		ll u,v,a,b;
		cin >> u >> v >> a >> b;
		adja[u][v] = adja[v][u] = a;
		adjb[u][v] = adjb[v][u] = a+b;
	}
	forar(k,n){
		forar(i,n){
			forar(j,n){
				adja[i][j] = min(adja[i][j],adja[i][k]+adja[k][j]);
				adjb[i][j] = min(adjb[i][j],adjb[i][k]+adjb[k][j]);
			}
		}
	}
	ll ans = mod * mod;
	forar(xp,n){
		forar(yp,n){
			forar(zp,n){
				ans = min(ans,adja[xp][yp]+adja[yp][zp]+adja[xp][zp] + adjb[x][xp]+adjb[y][yp]+adjb[z][zp]);
			}
		}
	}
	cout << ans << endl;
}
