//In The Name of Allah
//Tue 1/4/97
#pragma GCC optimize "-Ofast"
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0),cout << fixed << setprecision(12)
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

const ll mod = 10789,M = 2e5+100;

void Solution();

int32_t main()
{
	Init;
	auto _t1 = chrono::system_clock::now();
	Solution();
	auto _t2 = chrono::system_clock::now();
	cerr << endl << "Elapsed : " << ld((_t2 - _t1).count())/(1e9) << endl;
	return 0;
}

ll _mask;
ll n,ans;

ll ppow(ll base,ll exp,ll m = mod){
	if(!exp)
		return 1;
	ll v = ppow(base,exp/2);
	v = (v*v)%m;
	if(exp%2)
		v*=base;
	return v%m;
}

bool getbit(ll x,ll pos){
	return (x & (1<<pos) ? 1 : 0);
}

bool getcell(ll x,ll a,ll b){
	return getbit(x,n*a+b);
}

ll mcn;
ll mark[10][10];

void dfs(ll x,ll y){
	if(mark[x][y]==mcn || x>=n || y>=n || getcell(_mask,x,y))
		return;
	mark[x][y] = mcn;
	dfs(x,y+1);
	dfs(x+1,y);
}

inline void Solution(){
	n=5;
	ll kt = ppow(2,25,1000000000);
	for (;_mask < kt; ++_mask){
		mcn++;
		dfs(0,0);
		ans += mark[n-1][n-1] == mcn;
	}
	cout << ans%mod << endl;
}
