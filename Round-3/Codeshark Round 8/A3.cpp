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

const ll mod = 10789,M = 1e7+100;

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

ll n,ans;
ll phi[M],prephi[M];
bool mark[M];
bool sv[M];
vector<ll> pfac[M];

ll getphi(ll x){
	if(mark[x])
		return phi[x];
	mark[x] = 1;
	ll g = __gcd(x/pfac[x][0],pfac[x][0]);
	phi[x] = getphi(x/pfac[x][0]) * (pfac[x][0]-1)*g/getphi(g);
	if(phi[x] == 0)
		phi[x] = (pfac[x][0]-1);
	return phi[x];
}

void sieve(){
	fori(i,2,n+1){
		if(sv[i])
			continue;
		pfac[i].pb(i);
		for(ll j = i+i;j < n+1;j+=i){
			sv[j] = 1;
			pfac[j].pb(i);
		}
	}
}

inline void Solution(){
	n = 10000020;
	phi[1] = 1;
	mark[1] = 1;
	sieve();
	fori(i,2,n+1){
		if(i%100000 == 0)
			Log(i);
		prephi[i] = prephi[i-1] + getphi(i);
	}
	fori(g,1,n){
		ans += prephi[n/g]*g;
	}
	ans *= 4;
	ans += n*(n+1);
	Log(ans);
	cout << ppow(2,ans) << endl;
}
