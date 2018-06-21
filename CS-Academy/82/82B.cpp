//In The Name of Allah
//Tue 30/3/97
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

ll t[4];
ll p[4];
ll bun;

int32_t main()
{
	Init;
	Solution();
	return 0;
}

inline ll getans(ll thr){
	ll ans = thr*bun;
	forar(i,4){
		ans += max(0LL,t[i] - thr)*p[i];
	}
	return ans;
}

inline void Solution(){
	forar(i,4){
		cin >> t[i];
	}
	forar(i,4){
		cin >> p[i];
	}
	cin >> bun;
	ll ans = getans(0);
	forar(i,4){
		ans = min(ans,getans(t[i]));
	}
	cout << ans << endl;
}
