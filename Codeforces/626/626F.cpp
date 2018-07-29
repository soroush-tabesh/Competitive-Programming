//In The Name of Allah
//Sun 7/5/97
#pragma GCC optimize "-Ofast"
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0),cout << fixed << setprecision(12)
#define fori(i,a,b) for(int i = a; i < b;++i)
#define forar(i,n) fori(i,0,n)
#define WFile freopen("test.in","r",stdin),freopen("test.out","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define LSB(x) (x&(-x))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e5+100;

void Solution();

int32_t main(){
	Init;
	auto _t1 = chrono::system_clock::now();
	Solution();
	auto _t2 = chrono::system_clock::now();
	cerr << endl << "Elapsed : " << ld((_t2 - _t1).count())/(1e9) << endl;
	return 0;
}

int n,k,arr[210],dp[210][210][1010];
/*
bool mark[200][201][1001];

ll getdp(ll i, ll t,ll imb){
	if(imb < 0 || imb > k || t > n || t < 0 || i < 0 || i >= n)
		return 0;
	if(mark[i][t][imb] || i == 0)
		return dp[i][t][imb];
	mark[i][t][imb] = 1;
	ll delta = arr[i] - arr[i-1];
	return (dp[i][t][imb] = (getdp(i-1,t-1,imb-delta*(t-1))%mod 
					+ (getdp(i-1,t+1,imb-delta*(t+1))*(t+1))%mod
					+ (getdp(i-1,t,imb-delta*t)*(t+1))%mod)%mod);
}

inline void Solution(){
	cin >> n >> k;
	forar(i,n){
		cin >> arr[i];
	}
	sort(arr,arr+n);
	dp[0][0][0] = dp[0][1][0] = 1;
	mark[0][0][0] = mark[0][1][0] = 1;
	ll ans = 0;
	forar(imb,k+1){
		ans = (ans + getdp(n-1,0,imb))%mod;
	}
	cout << ans << endl;
}
*/

inline void madd(int &a,ll b){
	a = ((ll)a + b)%mod;
}

inline void Solution(){
	cin >> n >> k;
	forar(i,n){
		cin >> arr[i];
	}
	sort(arr,arr+n);
	dp[0][0][0] = dp[0][1][0] = 1;
	forar(i,n-1){
		forar(t,n+1){
			if(t > i+1)
				continue;
			forar(imb,k+1){
				ll delta = 1LL*t*(arr[i+1] - arr[i])+imb;
				if(!dp[i][t][imb] || delta > k)
					continue;
				madd(dp[i+1][t+1][delta], (ll)dp[i][t][imb]);
				madd(dp[i+1][t][delta], (t*1LL + 1)*dp[i][t][imb]);
				if(t)
					madd(dp[i+1][t-1][delta], ((ll)t)*dp[i][t][imb]);
			}
		}
	}
	ll ans = 0;
	forar(imb,k+1){
		ans = (ans + dp[n-1][0][imb])%mod;
	}
	cout << ans << endl;
}
