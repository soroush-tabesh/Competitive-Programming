//In The Name of Allah
//Fri 27/11/96
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
ll seq[M*5];

int main()
{
	Init;
	Solution();
	return 0;
}

ll ppow(ll base,ll exp){
	if(exp == 0)
		return 1;
	ll r = ppow(base,exp/2);
	r*=r;
	r%=mod;
	if(exp%2)
		r*=base;
	return r%mod;
}

inline void Solution(){
	cin >> n;
	forar(i,n){
		cin >> seq[i];
	}
	ll fn = 1;
	fori(i,2,n+1){
		fn = fn*(i);
		fn %= mod;
	}
	sort(seq,seq+n);
	ll ans = 0;
	ll mx = max_element(seq,seq+n)-seq;
	forar(i,mx){
		ll s = lower_bound(seq,seq+n,seq[i])-seq;
		ll sinv = ppow(n-s,mod-2);
		ans = (ans + ((fn*sinv)%mod)*seq[i])%mod;
	}
	cout << ans << endl;
}
