//In The Name of Allah
//Thr 28/4/97
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

const ll mod = 1e9+7,M = 2e5+100,inf = 1e17;

void Solution();

int32_t main(){
	Init;
	auto _t1 = chrono::system_clock::now();
	Solution();
	auto _t2 = chrono::system_clock::now();
	cerr << endl << "Elapsed : " << ld((_t2 - _t1).count())/(1e9) << endl;
	return 0;
}

ll n,lin[M],lout[M],dp[M];
bool mark[M];

ll getdp(ll x){
	if(mark[x])
		return dp[x];
	mark[x] = 1;
	dp[x] = inf;
	fori(t,1,4){
		if(t>x)
			break;
		do{
			ll res = 0;
			bool is = true;
			forar(i,t){
				is &= lin[x-t+i] != lout[x-t+i];
				res += abs(lin[x-t+i] - lout[x-t+i]);
			}
			if(!is)
				continue;
			dp[x] = min(dp[x],res+getdp(x-t));
		}while(next_permutation(lout+x-t,lout+x));
	}
	return dp[x];
}

inline void Solution(){
	cin >> n;
	forar(i,n){
		cin >> lin[i] >> lout[i];
	}
	sort(lin,lin+n);
	sort(lout,lout+n);
	mark[0] = 1;
	cout << getdp(n) << endl;
}
