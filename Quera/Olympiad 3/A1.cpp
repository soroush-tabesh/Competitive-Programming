//In The Name of Allah
//Tue 8/4/97
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

inline void Solution(){
	while(true)
	{
		int dt[3];
		forar(i,3){
			cin >> dt[i];
		}
		sort(dt,dt+3);
		dt[2] = min(dt[2],dt[1]+dt[0]-1);
		ll ans = 0;
		fori(i,1,dt[0]+1){
			fori(j,1,dt[1]+1){
				ans += max(min(dt[2]+1,i+j)-abs(i-j)-1,0);
				ans %= mod;
			}
		}
		cout << ans << endl;
	}
}
