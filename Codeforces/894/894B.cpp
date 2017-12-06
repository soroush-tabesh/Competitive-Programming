//In The Name of Allah
//Sun 28/8/96
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
	res=(res*res)%mod;
	if(exp%2)
		res*=base;
	return res%mod;
}

void Solution(){
	ll n,m,k;
	cin >> n >> m >> k;
	if(k == (-1) && (n%2) != (m%2)){
		cout << 0 << endl;
	}else if(n > 1 && m > 1){
		ll ans = ppow(2,n-1);
		ans = ppow(ans,m-1);
		cout << ans << endl;
	}else{
		cout << 1 << endl;
	}
}
