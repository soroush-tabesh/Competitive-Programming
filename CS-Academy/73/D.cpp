//In The Name of Allah
//Wed 23/12/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+100;

void Solution();

int n;
map<ll,ll,greater<ll> > cnt;
ll fac[M+1];
ll invfac[M+1];

int main()
{
	Init;
	Solution();
	return 0;
}

ll ppow(ll base,ll exp){
	if(exp == 0)
		return 1;
	ll res = ppow(base,exp/2);
	res *= res;
	res %= mod;
	if(exp % 2 == 1)
		res *= base;
	return (res%mod);
}

inline void Solution(){
	fac[0] = fac[1] = 1;
	fori(i,2,M+1){
		fac[i] = (fac[i-1]*i)%mod;
	}
	invfac[M] = ppow(fac[M],mod-2);
	for(ll i = M-1;i >= 0;i--){
		invfac[i] = ((i+1)*invfac[i+1])%mod;
	}
	cin >> n;
	ll mxsize = 0;
	ll ans = 1;
	forar(i,n){
		ll a;
		cin >> a;
		cnt[a]++;
		mxsize = max(mxsize,cnt[a]);
	}
	ans = invfac[mxsize];
	for(auto x : cnt){
		ans = (ans * ((fac[mxsize] * invfac[mxsize - x.S])%mod))%mod;
	}
	cout << ans << endl;
}
