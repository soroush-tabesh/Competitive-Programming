//In The Name of Allah
//Mon 28/3/97
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

ll n,k,ans;
ll dt[M];
ll psum[M];
ll jp[M];

int32_t main()
{
	Init;
	Solution();
	return 0;
}

inline void Solution(){
	cin >> n >> k;
	forar(i,n){
		cin >> dt[i];
		psum[i] = psum[max(0LL,i-1)]+dt[i];
	}
	psum[n] = psum[n-1];
	ll lst = n;
	for(ll i = n-1;i >= 0;i--){
		jp[i] = lst;
		if(dt[i] > 1)
			lst = i;
	}
	forar(i,n){
		ll pos = i;
		ll prod = 1;
		ll sum = 0;
		forar(dep,66){
			if(pos >= n || ld(prod)*ld(dt[pos]) > 1e18)
				break;
			prod *= dt[pos];
			sum += dt[pos];
			if(prod % k == 0){
				ll bnd = jp[pos] - pos - 1;
				ll bs = prod/k;
				if(sum+bnd >= bs && sum <= bs){
					ans ++;
				}
			}
			sum += jp[pos] - pos - 1;
			pos = jp[pos];
		}
	}
	cout << ans << endl;
}
