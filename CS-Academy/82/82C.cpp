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

int32_t main()
{
	Init;
	Solution();
	return 0;
}

ll n,s;
ll dst[M];

inline void Solution(){
	cin >> n >> s;
	forar(i,n){
		cin >> dst[i];
	}
	--s;
	ll nxt = (s+1)%n;
	ll prv = (s-1+n)%n;
	ll ans = 0;
	ll cov = 0;
	bool ps = false; // false is prv
	forar(i,n-1){
		ll dnxt = dst[(nxt-1+n)%n] + (ps ? 0:cov);
		ll dprv = dst[prv] + (ps ? cov:0);
		if(dnxt < dprv){
			cov += dst[(nxt-1+n)%n];
			ans += dnxt;
			nxt = (nxt+1)%n;
			ps = true;
		}else if(dnxt > dprv){
			cov += dst[prv];
			ans += dprv;
			prv = (prv-1+n)%n;
			ps = false;
		}else{
			if(nxt < prv){
				cov += dst[(nxt-1+n)%n];
				ans += dnxt;
				nxt = (nxt+1)%n;
				ps = true;	
			}else{
				cov += dst[prv];
				ans += dprv;
				prv = (prv-1+n)%n;
				ps = false;
			}
		}
	}
	cout << ans << endl;
}
