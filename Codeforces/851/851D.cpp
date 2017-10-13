//In The Name of Allah
//Mon 13/6/96
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(long long int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
#define Log(x) cout << "Log: " << x << endl
#define F first
#define S second
#define pb push_back
#define pf push_front

using namespace std;

typedef int64_t                                ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll mod = 1e9+7,M = 2e6+50;

void Solution();

ll n;
ll x,y;
ll data[M];
ll prefixCnt[M];
ll prefixSum[M];
bool smark[M];
vector<ll> primes;

int main()
{
	Init;
	#ifndef ONLINE_JUDGE
	//WFile;
	#endif
	Solution();
	return 0;
}

void sieve(){
	fori(i,2,M){
		if(!smark[i]){
			primes.pb(i);
			smark[i] = 1;
			for(ll j = 2*i;j < M;j+=i){
				smark[j] = 1;
			}
		}
	}
}

void Solution(){
	cin >> n >> x >> y;
	ll mxn = 0;
	sieve();
	forar(i,n){
		cin >> data[i];
		mxn = max(mxn,data[i]);
		prefixSum[data[i]] += data[i];
		prefixCnt[data[i]] += 1;
	}
	forar(i,M){
		prefixCnt[i+1] += prefixCnt[i];
		prefixSum[i+1] += prefixSum[i];
	}
	ll ans = x*n;
	for(ll p : primes){
		ll ml = -1;
		ll curans = 0;
		while((++ml)*p <= mxn){
			ll l = (ml)*p+1;
			ll r = (ml+1)*p-1;
			ll cutind = min(r-l+1,x/y);
			curans += (prefixCnt[r-cutind]-prefixCnt[l-1])*x;
			ll t = (prefixCnt[r]-prefixCnt[r-cutind])*(ml+1)*p;
			t -= (prefixSum[r]-prefixSum[r-cutind]);
			t *= y;
			curans += t; 
		}
		ans = min(ans,curans);
	}
	cout << ans;
}

