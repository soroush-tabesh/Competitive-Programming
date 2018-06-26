//In The Name of Allah
//Tue 5/4/97
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
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long int ll;
typedef __int128 lll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const lll mod = 1e10,M = 2e5+100;

void Solution();

int32_t main(){
	Init;
	auto _t1 = chrono::system_clock::now();
	Solution();
	auto _t2 = chrono::system_clock::now();
	cerr << endl << "Elapsed : " << ld((_t2 - _t1).count())/(1e9) << endl;
	return 0;
}

lll ppow(lll base,lll exp){
	if(exp == 0)
		return 1;
	lll v = ppow(base,exp/2);
	v *= v;
	v %= mod;
	if(exp%2)
		v*=base;
	return v%mod;
}

inline void Solution(){
	lll ans = 0;
	fori(i,1,1000000){
		ans += ppow(i,i);
		ans %= mod;
	}
	cout << ll(ans) << endl;
}
