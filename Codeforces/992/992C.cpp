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

ll x,k;

int32_t main()
{
	Init;
	Solution();
	return 0;
}

ll ppow(ll base,ll exp){
	if(exp == 0)
		return 1;
	ll v = ppow(base,exp/2);
	v*=v;
	v%=mod;
	if(exp%2)
		v*=base;
	return v%mod;
}

inline void Solution(){
	cin >> x >> k;
	if(x == 0){
		cout << 0 << endl;
		return;
	}
	ll res = x;
	ll hf = ppow(2,mod-2);
	if(k == 0){
		res = x;
	}else if(k==1){
		res = (res*2-hf+mod)%mod;
	}else{
		ll bias = (res*2-hf+mod)%mod;
		ll stp = (bias-hf+mod)%mod;
		res = bias + (stp*((ppow(2,k-1)-1+mod)%mod))%mod;
	}
	cout << (res*2)%mod << endl;
}
