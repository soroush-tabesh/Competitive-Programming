//In The Name of Allah
//Tue 19/4/97
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

const ll mod = 14653,M = 2e6+100;

void Solution();

int32_t main(){
	Init;
	auto _t1 = chrono::system_clock::now();
	Solution();
	auto _t2 = chrono::system_clock::now();
	cerr << endl << "Elapsed : " << ld((_t2 - _t1).count())/(1e9) << endl;
	return 0;
}

ll phi[M],sv[M],pfac[M],pref[M];

ll getphi(ll x){
	if(phi[x])
		return phi[x];
	if(!sv[x])
		return phi[x] = x-1;
	ll g = __gcd(x/pfac[x],pfac[x]);
	return phi[x] = getphi(x/pfac[x])*getphi(pfac[x])*g/getphi(g);
}

ll getprephi(ll x){
	if(!x)
		return 0;
	if(pref[x])
		return pref[x];
	return pref[x] = getprephi(x-1)+getphi(x)*(x%2);
}

void sieve(){
	phi[1] = 1;
	fori(i,2,M){
		if(sv[i])
			continue;
		pfac[i] = i;
		for(ll j = i+i;j < M;j+=i){
			pfac[j] = i;
			sv[j] = 1;
		}
	}
}

ll ppow(ll base,ll exp){
	if(exp == 0)
		return 1;
	ll v = ppow(base,exp/2);
	v *= v;
	v%=mod;
	if(exp%2)
		v*=base;
	return v%mod;
}

ll getans(ll n){
	ll ans = 0;
	fori(i,1,n+1){
		ans += getprephi(n/i)/2;
	}
	return ans;
}

inline void Solution(){
	ll n;
	sieve();
	cin >> n;
	cout << getans(n) << endl;
}
