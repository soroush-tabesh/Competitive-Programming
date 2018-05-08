//In The Name of Allah
//Tue 18/2/97
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

ll grid[24][24];
pii vect[4] = {{1,0},{1,1},{0,1},{-1,1}};

int32_t main()
{
	Init;
	Solution();
	return 0;
}

inline void Solution(){
	forar(i,20){
		forar(j,20){
			cin >> grid[i][j];
		}
	}
	ll mx = 0;
	forar(i,20){
		forar(j,20){
			forar(v,4){
				ll prod = 1;
				pii cur = {i,j};
				forar(k,4){
					prod *= grid[cur.F][cur.S];
					cur.F += vect[v].F;
					cur.S += vect[v].S;
					cur.F = (cur.F + 24)%24;
				}
				mx = max(prod,mx);
			}
		}
	}
	cout << mx << endl;
}
