//In The Name of Allah
//Mon 28/3/97
#pragma GCC optimize "-Ofast"
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

ll l,r,x,y;

int32_t main()
{
	Init;
	Solution();
	return 0;
}

inline void Solution(){
	cin >> l >> r >> x >> y;
	if(y%x){
		cout << 0 << endl;
		return;
	}
	ll ans = 0;
	ll tt = y/x;
	for(ll i = 1;i*i <= tt;i++){
		if(tt % i)
			continue;
		ll a = i*x;
		ll b = tt*x/i;
		ll g = __gcd(i,tt/i);
		if(g != 1)
			continue;
		if(a > r || b > r || b < l || a < l)
			continue;
		if(a == b)
			ans += 1;
		else
			ans += 2;
	}
	cout << ans << endl;
}
