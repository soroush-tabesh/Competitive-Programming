//In The Name of Allah
//Tue 1/4/97
#pragma GCC optimize "-Ofast"
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0),cout << fixed << setprecision(12)
#define fori(i,a,b) for(ll i = a; i < b;i++)
#define forar(i,n) fori(i,0,n)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define LSB(x) (x&(-x))

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 10789,M = 2e5+100;

void Solution();

int32_t main()
{
	Init;
	auto _t1 = chrono::system_clock::now();
	Solution();
	auto _t2 = chrono::system_clock::now();
	cerr << endl << "Elapsed : " << ld((_t2 - _t1).count())/(1e9) << endl;
	return 0;
}

ll ppow(ll base,ll exp){
	if(!exp)
		return 1;
	ll v = ppow(base,exp/2);
	v = (v*v)%mod;
	if(exp%2)
		v*=base;
	return v%mod;
}

inline void Solution(){
	ll n = 2020;
	ll ans = n*(n+1);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i+1; j <= n; ++j)
		{
			ans += 4*__gcd(i,j);
		}
	}
	Log(ans);
	ans = ppow(2,ans);
	cout << ans << endl;
}
