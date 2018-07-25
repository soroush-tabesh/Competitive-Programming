//In The Name of Allah
//Wed 3/5/97
#pragma GCC optimize "-Ofast"
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0),cout << fixed << setprecision(12)
#define fori(i,a,b) for(int i = a; i < b;++i)
#define forar(i,n) fori(i,0,n)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define LSB(x) (x&(-x))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+100;

void Solution();

int32_t main(){
	Init;
	auto _t1 = chrono::system_clock::now();
	Solution();
	auto _t2 = chrono::system_clock::now();
	cerr << endl << "Elapsed : " << ld((_t2 - _t1).count())/(1e9) << endl;
	return 0;
}

ll n,m,dp[1<<20][20],ans;
bool adj[20][20];

inline void Solution(){
	cin >> n >> m;
	forar(i,m){
		int a,b;
		cin >> a >> b;
		--a,--b;
		adj[a][b] = adj[b][a] = 1;
		dp[(1<<a)||(1<<b)][max(a,b)] = 1;
	}
	fori(mask,1,1<<n){
		forar(i,n){
			if(!(mask&(1<<i)) || LSB(mask) == (1<<i))
				continue;
			forar(j,n){
				if(!adj[i][j] || !(mask&(1<<j)) || LSB(mask) == (1<<j))
					continue;
				cout << mask << " " << i+1 << " " << j+1 << endl;
				dp[mask][i] += dp[mask^(1<<i)][j];
			}
			int t = LSB(mask);
			while(t&1 == 0)
				t>>=1;
			if(adj[i][t])
				ans += dp[mask][i];
		}
	}
	cout << ans/2 << endl;
}
