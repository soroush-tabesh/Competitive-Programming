//In The Name of Allah
//Wed 11/11/96
#pragma GCC optimize "-O3"
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

ll a,b,p,x;
ll ord[M*5];

int main()
{
	Init;
	Solution();
	return 0;
}

ll ppow(ll base,ll exp,ll m){
	if(exp == 0)
		return 1;
	ll r = ppow(base,exp/2,m);
	r*=r;
	if(exp%2)
		r*=base;
	return (r%m);
}

inline void Solution(){
	cin >> a >> b >> p >> x;
	ord[0] = 1;
	fori(i,1,p){
		ord[i] = (a*ord[i-1])%p;
	}
	ll ans = 0;
	ll t1 = ppow(p-1,p-2,p)*(p-1);
	ll t2 = ppow(p,p-3,p-1)*p;
	ll bn = p*(p-1);
	forar(i,p-1){
		ll inv = ord[p-1-i];
		ll r = (b*inv)%p;
		ll ax = (r*t1 + i*t2)%bn;
		if(ax <= x)
			ans += (x-ax)/bn + 1;
	}
	cout << ans << endl;
}
