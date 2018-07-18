//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define pf push_front

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll delta = 10259;

void SolutionA();

int main()
{
	Init;
	//WFile;
	SolutionA();
	return 0;
}

ll ppow(ll base,ll exp,bool usedelta = true){
	if(exp == 0)
		return 1;
	if(exp == 1)
		return base%delta;
	ll v = ppow(base,exp/2);
	v*=v;
	if(exp % 2 == 1)
		v*=base;
	if(usedelta)
		v%=delta;
	return v;
}

ll dpf[50];

ll funcf(ll x){
	if(x == 2)
		return 3;
	if(x == 3)
		return 5;
	if(dpf[x] != 0)
		return dpf[x];
	dpf[x] = funcf(x-1) + funcf(x-2);
	dpf[x] %= delta;
	return dpf[x];
}

void SolutionA(){
	ll n = 20;
	ll ans = 0;
	fori(x,2,n+1){
		ll res = 1;
		for(ll xpow = 23;xpow > 0;xpow--){
			ll t = (n/ppow(x,xpow,false));
			t -= 2*(n/ppow(x,xpow+1,false));
			res *= ppow(funcf(xpow+1),t);
			res %= delta;
		}
		res *= ppow(2,n-(n/x)-1);
		res %= delta;
		res = ppow(2,n)-res;
		res += delta;
		res %= delta;
		
		ans += res;
		ans %= delta;
	}
	cout << ans << endl;
}

