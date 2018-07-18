//In The Name of Allah
//Sun 24/4/97
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

const ll mod = 10513,M = 2e5+100;

void Solution();

int32_t main(){
	Init;
	auto _t1 = chrono::system_clock::now();
	Solution();
	auto _t2 = chrono::system_clock::now();
	cerr << endl << "Elapsed : " << ld((_t2 - _t1).count())/(1e9) << endl;
	return 0;
}

int n,m,ans;
bool gr[10][10];
char mark[10][10];

void solve(int i,int j){
	if(i == n){
		memset(mark,0,sizeof mark);
		forar(tj,m){
			if(gr[0][tj])
				break;
			mark[0][tj] |= 1;
		}
		forar(tj,m){
			if(gr[n-1][m-tj-1])
				break;
			mark[n-1][m-tj-1] |= 2;
		}
		bool fl = false;
		int cn = 0;
		forar(tj,m){
			bool is = true;
			forar(ti,n){
				is &= !gr[ti][tj];
			}
			if(mark[0][tj]&1 && mark[n-1][tj]&2 && is){
				++cn;
				if(tj == m-1)
					fl = true;
			}
		}
		if(cn == 1 && fl)
			++ans;
		return;
	}
	if(j == m){
		solve(i+1,0);
		return;
	}
	solve(i,j+1);
	gr[i][j] = 1;
	solve(i,j+1);
	gr[i][j] = 0;
}

inline void Solution(){
	cin >> n >> m;
	solve(0,0);
	cout << ans << endl;
	int _n,_m;
	cin >> _n >> _m;
	forar(i,_n){
		forar(j,_m){
			n = i+1;
			m = j+1;
			ans = 0;
			solve(0,0);	
			cout << ans << " ";
			//cout << ans%mod << endl;
		}
		cout << endl;
	}
}
