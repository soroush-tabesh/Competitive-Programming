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

const ll mod = 10259,M = 2e6+100;

void Solution();

int32_t main(){
	Init;
	auto _t1 = chrono::system_clock::now();
	Solution();
	auto _t2 = chrono::system_clock::now();
	cerr << endl << "Elapsed : " << ld((_t2 - _t1).count())/(1e9) << endl;
	return 0;
}

ll n, pcn[M][23], suf[M], fibo[M];

ll ppow(ll base,ll exp){
	if(exp == 0)
		return 1;
	ll v = ppow(base,exp/2);
	v*=v;
	if(exp%2)
		v*=base;
	return v%mod;
}

inline void Solution(){
	cin >> n;
	fibo[0] = 1;
	fibo[1] = 2;
	fori(i,2,n+1){
		fibo[i] = (fibo[i-1]+fibo[i-2])%mod;
	}
	fori(i,1,n+1){
		ll ptr = 2;
		while(ptr*i <= n){
			ll cnt = 0;
			ll tmp = i;
			while(tmp <= n){
				++cnt;
				tmp *= ptr;
			}
			pcn[ptr][cnt]++;
			++ptr;
		}
		suf[ptr]++;
	}
	ll tsuf = 0;
	fori(i,2,n+1){
		tsuf += suf[i];
		pcn[i][1] += tsuf;
	}
	ll ans = 0;
	fori(i,2,n+1){
		ll differ = 0;
		ll res = 1;
		for(int pw = 23;pw >= 1;--pw){
			pcn[i][pw] -= differ;
			differ += pcn[i][pw];
			res = (res * ppow(fibo[pw],pcn[i][pw]))%mod;
		}
		res = (ppow(2,n) - res+mod)%mod;
		ans = (ans + res)%mod;
	}
	cout << ans << endl;
}
