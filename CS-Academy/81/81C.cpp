//In The Name of Allah
//Tue 16/3/97
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
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

const ll mod = 1e9+7,M = 2e5+100;

void Solution();

ll n,dig[10];
ll fac[100],facinv[100];

int32_t main()
{
	Init;
	Solution();
	return 0;
}

ll ppow(ll base,ll exp){
	if(exp == 0)
		return 1;
	ll v = ppow(base,exp/2);
	v *= v;
	if(exp%2)
		v=(v%mod)*base;
	return v%mod;
}

ll getans(){
	ll res = 0;
	ll denom = 1;
	forar(i,10){
		ll t = (ppow(10,n)-1+mod)%mod;
		t = (t*ppow(9,mod-2))%mod;
		t = (t*i)%mod;
		t = (t*fac[n-1])%mod;
		
		res += (t*dig[i])%mod;
		res %= mod;
		
		denom *= facinv[dig[i]];
		denom %= mod;
	}
	res = (res*denom)%mod;
	return res;
}

inline void Solution(){
	fac[0] = fac[1] = 1;
	fori(i,2,100){
		fac[i] = fac[i-1]*i;
		fac[i] %= mod;
	}
	facinv[99] = ppow(fac[99],mod-2);
	for(ll i = 98;i >= 0;i--){
		facinv[i] = facinv[i+1]*(i+1);
		facinv[i] %= mod;
	}
	
	cin >> n;
	forar(i,n){
		int a;
		cin >> a;
		dig[a]++;
	}
	ll ans = getans();
	if(dig[0]){
		dig[0]--;
		n--;
		ans -= getans();
		ans += mod;
		ans %= mod;
	}
	cout << ans << endl;
}
