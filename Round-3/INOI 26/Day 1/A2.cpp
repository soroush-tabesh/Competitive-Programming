//In The Name of Allah
//Tue 9/5/97
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

const ll mod = 10181,M = 2e5+100;

void Solution();

int32_t main(){
	Init;
	auto _t1 = chrono::system_clock::now();
	Solution();
	auto _t2 = chrono::system_clock::now();
	cerr << endl << "Elapsed : " << ld((_t2 - _t1).count())/(1e9) << endl;
	return 0;
}

ll dp[100];

ll ppow(ll base,ll exp,ll md = true){
	if(exp == 0)
		return 1;
	ll v = ppow(base,exp,md);
	if(md){
		v = (v*v)%mod;
		if(exp%2)
			v *= base;
		return v%mod;
	}else{
		v *= v;
		if(exp%2)
			v *= base;
		return v;
	}
}

ll solve(ll n,ll k){
	if((1LL<<n) == k)
		return dp[n];
	if(n == 1 || k == 1){
		return 0;
	}
	ll res = 1LL<<(n-1);
	ll pnm = res;
	if(k-pnm == 1){
		res += dp[n-1];
	}else if(k-pnm > 1){
		res += dp[n-1]+1;
		res += solve(n-1,k-pnm);
	}else{
		if(k > 1)
			res += solve(n-1,k-1);
	}
	return res%mod;
}

inline void Solution(){
	ll p = 1;dp[1] = 1;
	fori(i,2,100){
		dp[i] = (2*dp[i-1] + (p = (2*p)%mod)+ 1)%mod;
	}
	ll n,k;
	cin >> n >> k;
	cout << solve(n,k) << endl;
}
