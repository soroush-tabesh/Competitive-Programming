//In The Name of Allah
//Wed 27/4/97
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

const ll mod = 10259,M = 2e5+100;

void Solution();

int32_t main(){
	Init;
	auto _t1 = chrono::system_clock::now();
	Solution();
	auto _t2 = chrono::system_clock::now();
	cerr << endl << "Elapsed : " << ld((_t2 - _t1).count())/(1e9) << endl;
	return 0;
}

ll fac[M],ifac[M];

ll ppow(ll base,ll exp){
	if(exp == 0)
		return 1;
	ll v = ppow(base,exp/2);
	v*=v;
	if(exp%2)
		v*=base;
	return v%mod;
}

ll getsum(ll beg,ll en){
	beg=max(0LL,beg-1);
	return ((en*(en+1)*ppow(2,mod-2)) - (beg*(beg+1)*ppow(2,mod-2)))%mod;
}

ll getcomb(ll n,ll r){
	return (((fac[n]*ifac[r])%mod)*ifac[n-r])%mod;
}

inline void Solution(){
	int n;
	cin >> n;

	fac[0] = 1;
	fori(i,1,n+10){
		fac[i] = (i*fac[i-1])%mod;
	}
	ifac[n+9] = ppow(fac[n+9],mod-2);
	for(int i = n+8;i >= 0;--i){
		ifac[i] = (ifac[i+1]*(i+1))%mod;
	}

	ll ptr = 0;
	ll ans = 0;
	forar(i,n+1){
		ll sum = getsum(ptr,(ptr+getcomb(n,i)-1)%mod);
		sum = (sum * ppow(2,i))%mod;
		ans = (ans+sum)%mod;
		ptr = (ptr+getcomb(n,i))%mod;
	}
	cout << ans << endl;
}
