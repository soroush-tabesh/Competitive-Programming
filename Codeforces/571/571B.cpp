//In The Name of Allah
//Wed 3/5/97
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

const ll mod = 1e9+7,M = 3e5+100,inf = 1e18,M2 = 5100;

void Solution();

int32_t main(){
	Init;
	auto _t1 = chrono::system_clock::now();
	Solution();
	auto _t2 = chrono::system_clock::now();
	cerr << endl << "Elapsed : " << ld((_t2 - _t1).count())/(1e9) << endl;
	return 0;
}

ll n,k;
ll arr[M],dp[M2][M2];
bool mark[M2][M2];

ll getdp(ll x,ll y){ // floor-ceil
	if(mark[x][y])
		return dp[x][y];
	mark[x][y] = 1;
	ll fl = n/k,cl = (n+k-1)/k;
	ll i = fl*x + cl*y - 1;
	return dp[x][y] = min(y ? (getdp(x,y-1)+arr[i]-arr[i-cl+1]) : inf,x ? (getdp(x-1,y)+arr[i]-arr[i-fl+1]) : inf);
}

inline void Solution(){
	cin >> n >> k;
	forar(i,n){
		cin >> arr[i];
	}
	sort(arr,arr+n);
	mark[0][0] = 1;
	cout << getdp(k-n%k,n%k) << endl;
}
