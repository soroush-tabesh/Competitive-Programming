//In The Name of Allah
//Mon 18/10/96
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

const ll mod = 1e9+7,M = 1e5+100;

void Solution();

ll n,l,inf = ll(1e18);
pll bt[40];
ll wst[40];

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
	if(exp%2)
		res*=base;
	return res;
}

bool comp(pll a,pll b){
	return (a.F*b.S) < (a.S*b.F) || ((a.F*b.S) < (a.S*b.F) && a.S < b.S);
}

ll slv(ll x,ll i = 0){
	ll ans = 0;
	ll d = x/bt[i].S;
	ans += bt[i].F*d;
	x -= bt[i].S*d;
	if(x>0){
		return min(slv(x,i+1),bt[i].F)+ans;
	}else{
		return ans;
	}
}

void Solution(){
	cin >> n >> l;
	forar(i,n){
		cin >> bt[i].F;
		bt[i].S = ppow(2,i);
	}
	sort(bt,bt+n,comp);
	ll ans = slv(l);
	cout << ans << endl;
}
