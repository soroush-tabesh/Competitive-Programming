//In The Name of God
#include <bits/stdc++.h>

#define Init ios_base::sync_with_stdio(0),cin.tie(0)
#define forar(i,n) for(int i = 0; i < n;i++)
#define fori(i,a,b) for(long long int i = a; i < b;i++)
#define ford(i,a,b) for(long long int i = a; i > b;i--)
#define WFile freopen("in.txt","r",stdin),freopen("out.txt","w",stdout)
#define Log(x) cout << "Log: " << x << endl;
#define F first
#define S second
#define pb push_back
#define pf push_front

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll delta = 12841;

void SolutionA();

vector<ll> bases;
ll dp[3000*1000];

int main()
{
	Init;
	//WFile;
	SolutionA();
	return 0;
}

ll ppow(ll base,ll exp){
	if(exp == 0)
		return 1;
	if(exp == 1)
		return base;
	ll v = ppow(base,exp/2);
	v*=v;
	v%=delta;
	if(exp % 2 == 1)
		v *= base;
	v%=delta;
	return v;
}

ll solve(ll x){
	if(x < 0)
		return 1e9;
	if(x == 0)
		return 0;
	if(x == 1)
		return 1;
	if(dp[x] != 0)
		return dp[x];
	dp[x] = 1e9;
	ll i = 0;
	while(bases[i] <= x){
		dp[x] = min(dp[x],solve(x-bases[i])+1);
		i++;
	}
	return dp[x];
}

void SolutionA(){
	ll n1,n2;
	cin >> n1 >> n2;
	bases.pb(1);
	fori(i,2,10000){
		ll t = i;
		t*=i+1;
		t/=2;
		t+=bases.back();
		bases.pb(t);
	}
	ll ans = 0;
	forar(i,n1){
		solve(i);
	}
	fori(i,n1,n2+1){
		ll t = solve(i);
		t = ppow(t,i);
		ans += t;
		ans %= delta;
	}
	cout << ans << endl;
}
