//In The Name of Allah
//Sat 30/4/97
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

const ll mod = 1390700000000LL,M = 2e5+100;

void Solution();

int32_t main(){
	Init;
	auto _t1 = chrono::system_clock::now();
	Solution();
	auto _t2 = chrono::system_clock::now();
	cerr << endl << "Elapsed : " << ld((_t2 - _t1).count())/(1e9) << endl;
	return 0;
}

ll ppow(ll base,ll exp){
	if(exp == 0)
		return 1;
	ll v = ppow(base,exp/2);
	v *= v;
	if(exp%2)
		v*=base;
	return v%mod;
}

inline void Solution(){
	ll n;
	cin >> n;
	ll ans = (n*ppow(2,n))%mod;
	for(ll d1 = 1;d1*d1 <= n;++d1){
		if(n%d1)
			continue;
		ll d2 = n/d1;
		ans = (ans+mod-(d2*ppow(2,d1))%mod)%mod;
		ans = (ans+mod-(d1*ppow(2,d2))%mod)%mod;
	}
	cout << ans << endl;
}
