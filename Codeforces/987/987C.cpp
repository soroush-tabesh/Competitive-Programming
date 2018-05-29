//In The Name of Allah
//Tue 8/3/97
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

ll n;
ll sz[M],dp[3][M];

int32_t main()
{
	Init;
	Solution();
	return 0;
}

inline void Solution(){
	cin >> n;
	ll inf = 1e10;
	forar(i,n){
		cin >> sz[i];
	}
	forar(i,n){
		cin >> dp[0][i];
	}
	forar(i,n){
		dp[1][i] = inf;
	}
	forar(i,n){
		dp[2][i] = inf;
	}
	set<pll> srt[3];
	fori(lay,1,3){
		for(int i = n-1;i >= 0;i--){
			auto it = srt[lay-1].upper_bound(mp(sz[i],inf));
			while(it != srt[lay-1].end()){
				dp[lay][i] = min(dp[lay][i],it->S+dp[0][i]);
				++it;
			}
			srt[lay-1].emplace(sz[i],dp[lay-1][i]);
		}
	}
	ll ans = inf;
	forar(i,n){
		ans = min(ans,dp[2][i]);
	}
	if(ans >= inf)
		ans = -1;
	cout << ans << endl;
}
