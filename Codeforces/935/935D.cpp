//In The Name of Allah
//Mon 30/11/96
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

ll n,m;
ll s1[M],s2[M],t1,t2;

int main()
{
	Init;
	Solution();
	return 0;
}

ll ppow(ll base,ll exp){
	if(exp == 0)
		return 1;
	ll res = ppow(base,exp/2);
	res*=res;
	res %= mod;
	if(exp%2)
		res *= base;
	return res % mod;
}

ll solve(int ind){
	if(ind >= n)
		return 0;
	if(s1[ind] == 0 && s2[ind] == 0){
		ll res = ((m-1)*t2)%mod;
		res = (res + solve(ind+1)*t1)%mod;
		return res;
	}else if(s1[ind] == 0){
		ll res = ((m-s2[ind])*t1)%mod;
		res = (res + solve(ind+1)*t1)%mod;
		return res;
	}else if(s2[ind] == 0){
		ll res = ((s1[ind]-1)*t1)%mod;
		res = (res + solve(ind+1)*t1)%mod;
		return res;
	}else{
		if(s1[ind] == s2[ind])
			return solve(ind+1);
		else if(s1[ind] > s2[ind])
			return 1;
		else
			return 0;
	}
}

inline void Solution(){
	cin >> n >> m;
	forar(i,n){
		cin >> s1[i];
	}
	forar(i,n){
		cin >> s2[i];
	}
	t1 = ppow(m,mod-2);
	t2 = ppow(2*m,mod-2);
	cout << solve(0) << endl;
}
