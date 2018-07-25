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

ll n,m;
bool adj[25][25],mark[1<<22];

inline void Solution(){
	cin  >> n >> m;
	if(m == (n*(n-1))){
		cout << 0 << endl;
		return;
	}
	forar(i,m){
		int a,b;
		cin >> a >> b;
		--b,--a;
		adj[a][b] = adj[b][a] = 1;
	}
	mark[0] = 1;
	forar(i,n){
		mark[1<<i] = 1;
	}
	fori(mask,1,1<<n){
		forar(i,n){
			if(!(mask & (1<<i)) || !mark[mask^(1<<i)])
				continue;
			forar(j,n){
				mark[mask] |= (mask&(1<<j))&&adj[i][j];
			}
			break;
		}
	}
	ll ans = 25;
	ll mans = 0;
	fori(mask,1,1<<n){
		bool is = mark[mask];
		forar(i,n){
			is &= mark[mask|(1<<i)];
		}
		if(is){
			if(__builtin_popcount(mask) < ans){
				ans = __builtin_popcount(mask);
				mans = mask;
			}
		}
	}
	cout << ans << endl;
	forar(i,24){
		if(mans&(1<<i)){
			cout << i+1 << " ";
		}
	}
}
