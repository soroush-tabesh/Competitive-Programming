//In The Name of Allah
//Fri 29/4/97
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

const ll mod = 13907000000LL,M = 2e5+100;

void Solution();

int32_t main(){
	Init;
	auto _t1 = chrono::system_clock::now();
	while(true)Solution();
	auto _t2 = chrono::system_clock::now();
	cerr << endl << "Elapsed : " << ld((_t2 - _t1).count())/(1e9) << endl;
	return 0;
}

inline void Solution(){
	int n,ans = 0;
	cin >> n;
	forar(i,1<<n){
		forar(j,1<<n){
			bool is = false;
			forar(t,n){
				int a1 = i<<t;
				a1 &= (1<<n)-1;
				int a2 = i>>(n-t);
				is |= (j == (a1|a2));
			}
			ans += is;
		}
	}
	cout << ans%mod << endl;
}
