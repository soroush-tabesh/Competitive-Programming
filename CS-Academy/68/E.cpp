//In The Name of Allah
//Wed 18/11/96
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

ll n,k,m;

int main()
{
	Init;
	Solution();
	return 0;
}

ll solve(ll x){
    __int128 ret = 1;
	ll den = x+1;
    for (ll i = n+1; i > n-x; i--){
        ll t = __gcd(den,i);
		den /= t;
        ret = (ret*(i/t))% m;
    }
    return ret;
}

inline void Solution(){
	cin >> n >> k >> m;
	ll ans = 0;
	k = min(k,n);
	fori(i,1,k+1){
		ans = (ans+solve(i))%m;
	}
	cout << ans << endl;
}
