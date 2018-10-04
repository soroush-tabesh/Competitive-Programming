//In The Name of Allah
//tue 1/5/97
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

const ll mod = 1e9+7,M = 2e6+100,inf = 1e18;

void Solution();

int32_t main(){
	Init;
	auto _t1 = chrono::system_clock::now();
	Solution();
	auto _t2 = chrono::system_clock::now();
	cerr << endl << "Elapsed : " << ld((_t2 - _t1).count())/(1e9) << endl;
	return 0;
}

ll n,a,b;
ll arr[M];
ll dp[M][3];// 0:no-removing 1:strict-suf 2:non-touch-interval

ll solve(ll g,int st,int en){
	if(g == 1)
		return inf;
	dp[st][1] = a;
	dp[st][2] = inf;
	if(arr[st]%g == 0)
		dp[st][0] = 0;
	else if(arr[st]%g == 1 || arr[st]%g==g-1)
		dp[st][0] = b;
	else
		dp[st][0] = inf;
	fori(i,st+1,en){
		dp[i][1] = min(dp[i-1][0],dp[i-1][1])+a;
		if(arr[i]%g == 0){
			dp[i][0] = dp[i-1][0];
			dp[i][2] = min(dp[i-1][2],dp[i-1][1]);
		}else if(arr[i]%g == 1 || arr[i]%g==g-1){
			dp[i][0] = dp[i-1][0] + b;
			dp[i][2] = min(dp[i-1][2],dp[i-1][1])+b;
		}else{
			dp[i][0] = inf;
			dp[i][2] = inf;
		}
		dp[i][0] = min(dp[i][0],inf);
		dp[i][2] = min(dp[i][2],inf);
	}
	return min(dp[en-1][0],min(dp[en-1][1],dp[en-1][2]));
}

inline void Solution(){
	cin >> n >> a >> b;
	forar(i,n){
		cin >> arr[i];
	}
	ll ans = inf;
	vector<int> lst;
	fori(i,-1,2){
		//lst.pb
	}
	for(ll d = 1;d*d <= max(arr[0],arr[n-1]);++d){
		if(arr[0]%d && arr[n-1]%d)
			continue;
		if(arr[0]%d==0){
			ans = min(ans,solve(arr[0]/d,1,n));
			ans = min(ans,solve(d,1,n));
		}
		if(arr[n-1]%d==0){
			ans = min(ans,solve(arr[n-1]/d,0,n-1));
			ans = min(ans,solve(d,0,n-1));
		}
	}
	cout << ans << endl;
}
