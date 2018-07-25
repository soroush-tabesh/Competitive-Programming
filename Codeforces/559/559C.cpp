//In The Name of Allah
//Tue 1/5/97
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

ll h,w,n;
pll bl[3000];
ll dp[3000];
ll fac[M],ifac[M];

ll ppow(ll base, ll exp){
	if(exp == 0)
		return 1;
	ll v = ppow(base,exp/2);
	v *= v;
	v %= mod;
	if(exp%2)
		v*=base;
	return v%mod;
}

ll combine(ll n,ll r){
	return (((fac[n]*ifac[r])%mod)*ifac[n-r])%mod;
}

inline void Solution(){
	fac[0] = 1;
	for(ll i = 1;i < M;++i){
		fac[i] = (i*fac[i-1])%mod;
	}
	ifac[M-1] = ppow(fac[M-1],mod-2);
	for(ll i =  M-2;i >= 0;--i){
		ifac[i] = (ifac[i+1]*(i+1))%mod;
	}
	cin >> h >> w >> n;
	forar(i,n){
		cin >> bl[i].F >> bl[i].S;
		--bl[i].F;--bl[i].S;
	}
	bl[n].F = h-1;bl[n].S=w-1;
	sort(bl,bl+n);
	forar(i,n+1){
		dp[i] = combine(bl[i].F+bl[i].S,bl[i].F);
		forar(j,i){
			if(bl[j].S > bl[i].S)
				continue;
			dp[i] = (dp[i] + mod - (dp[j]*combine(bl[i].F-bl[j].F+bl[i].S-bl[j].S,bl[i].F-bl[j].F))%mod)%mod;
		}
	}
	cout << dp[n] << endl;
}
